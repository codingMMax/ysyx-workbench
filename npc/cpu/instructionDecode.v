`include "defines.v"
/*decode the input instructions and output specific control signals based on decoded command type*/
module instructionDecode (
    input [`INS_BUS] instruction,  // input instruction
    //register address input to register file
    output [4:0] rs1,  // rs1 register
    output [4:0] rs2,  // rs2 regisrter
    output [4:0] rd,  // rd register
    output regWEN,  // write enable to register file
    output memtoReg,  // write read memory data back to register file 
    // inputs to ALU 
    output [3:0] ALUop,  // define the ALU operation types
    output [2:0] branchType, // define the type of branch so that ALU will set the output branch signal 
    output immSrc,  // if this command is I-type require immdiate operand
    output PCsrc,  // check if pc is required to input ALU
    // output SLTtype,  // check the SLT command type
    //inputs to memory module
    output [1:0] memOp,  //define the memory operation type
    output [1:0] memSize,  // memory operation size
    // inputs to imm generator    
    output [2:0] immShiftOp,  // imm shift operation types
    output immBitWidth,  // if the imm is 12bit 
    output [`Imm_20] imm,
    // input to instruction fetch/PC
    output jmp  // if requires a address jump
);
  // itermidiate decode parameters
  reg [6:0] opcode;
  reg [6:0] fct7;
  reg [2:0] fct3;

  always @(*) begin
    opcode = instruction[6:0];
    case (opcode)
      // R-Type add,xor,or,and,sub,sll,slt,sltu,srl,sra
      7'b0110011: begin
        fct7 = instruction[31:25];
        fct3 = instruction[14:12];
        rd = instruction[11:7];
        rs1 = instruction[19:15];
        rs2 = instruction[24:20];
        imm = 0;
        immBitWidth = `noBit;
        branchType = `BNO;
        memOp = `MEMNO;
        memSize = `byteMem;
        jmp = 0;
        immSrc = 0;
        memtoReg = 0;
        immShiftOp = `no_shift;
        regWEN = 1;
        PCsrc = 0;
        case (fct7)
          7'b0100000: begin  // sub or sra
            case (fct3)
              3'b000: ALUop = `ALU_SUB;  // sub
              3'b101: ALUop = `ALU_SAR;  // sra
              default: begin
                ALUop = `ALU_NO;
              end
            endcase
          end
          7'b0000000: begin  // ADD SLTU OR SLL XOR AND SLT SRL
            case (fct3)
              3'b000: ALUop = `ALU_ADD;  // ADD
              3'b001: ALUop = `ALU_SLL;  // SLL
              3'b010: ALUop = `ALU_SCOMP;  // SLT
              3'b011: ALUop = `ALU_UCOMP;  //SLTU
              3'b100: ALUop = `ALU_XOR;  // XOR
              3'b101: ALUop = `ALU_SLR;  //SRL
              3'b110: ALUop = `ALU_OR;  //OR
              3'b111: ALUop = `ALU_AND;  //AND
            endcase
          end
        endcase
      end

      // I-Type addi,slti,sltu,xori,ori,andi
      7'b0010011: begin
        fct7 = 0;
        fct3 = instruction[14:12];
        rd = instruction[11:7];
        rs1 = instruction[19:15];
        rs2 = 0;
        imm = {{8'b0}, instruction[31:20]};
        immBitWidth = `is12Bit;
        branchType = `BNO;
        memOp = `MEMNO;
        memSize = `byteMem;
        jmp = 0;
        memtoReg = 0;
        immSrc = 1;
        immShiftOp = `sign_shift;
        regWEN = 1;
        PCsrc = 0;
        case (fct3)
          3'b000: ALUop = `ALU_ADD;  // addi
          3'b010: ALUop = `ALU_SCOMP;  // slti
          3'b011: begin
            ALUop = `ALU_UCOMP;
            immShiftOp = `unsign_shift;
          end  // sltiu
          3'b100: ALUop = `ALU_XOR;  // xori
          3'b110: ALUop = `ALU_OR;  // ori
          3'b111: ALUop = `ALU_AND;  // andi
        endcase
      end

      // I-Type load,LB,LH,LW,LBU,LHU
      7'b0000011: begin
        fct7 = 0;
        fct3 = instruction[14:12];
        rd = instruction[11:7];
        rs1 = instruction[19:15];
        rs2 = 0;
        imm = {{8'b0}, instruction[31:20]};
        immBitWidth = `is12Bit;
        branchType = `BNO;
        jmp = 0;
        memtoReg = 1;
        immSrc = 1;
        regWEN = 1;
        ALUop = `ALU_NO;
        PCsrc = 0;
        case (fct3)
          3'b000: begin
            memSize = `byteMem;
            memOp = `MEML;
            immShiftOp = `sign_shift;
          end  // LB
          3'b001: begin
            memSize = `hwMem;
            memOp = `MEML;
            immShiftOp = `sign_shift;
          end  // LH
          3'b010: begin
            memSize = `fwMem;
            memOp = `MEML;
            immShiftOp = `sign_shift;
          end  // LW
          3'b011: begin
            memSize = `dwMem;
            memOp = `MEML;
            immShiftOp = `sign_shift;
          end  // LD
          3'b100: begin
            memSize = `byteMem;
            memOp = `MEMLU;
            immShiftOp = `unsign_shift;
          end  // LBU
          3'b101: begin
            memSize = `hwMem;
            memOp = `MEMLU;
            immShiftOp = `unsign_shift;
          end  // LHU
          3'b110: begin
            memSize = `fwMem;
            memOp = `MEMLU;
            immShiftOp = `unsign_shift;
          end  // LWU
          default: begin
            memSize = `byteMem;
            memOp = `MEMNO;
            immShiftOp = `no_shift;
          end
          default: begin
            memSize = `byteMem;
            memOp = `MEMNO;
            immShiftOp = `no_shift;
          end
        endcase

      end

      // S-type store, SB SH SW SD
      7'b0100011: begin
        fct7 = 0;
        fct3 = instruction[14:12];
        rd = 0;
        rs1 = instruction[19:15];
        rs2 = instruction[24:20];
        imm = {{8'b0}, {instruction[31:25]}, {instruction[11:7]}};
        immBitWidth = `is12Bit;
        branchType = `BNO;
        jmp = 0;
        memtoReg = 0;
        immSrc = 1;
        regWEN = 0;
        ALUop = `ALU_NO;
        memOp = `MEMS;
        immShiftOp = `no_shift;
        case (fct3)
          3'b000: memSize = `byteMem;  //SB
          3'b001: memSize = `hwMem;  // SH
          3'b010: memSize = `fwMem;  // SW
          3'b011: memSize = `dwMem;  // SD
          default: begin
            memSize = `byteMem;
            memOp   = `MEMNO;
          end
        endcase

      end
      // U-type LUI
      7'b0110111: begin
        fct7 = 0;
        fct3 = 0;
        rd = instruction[11:7];
        rs1 = 0;
        rs2 = 0;
        imm = instruction[31:12];
        immBitWidth = `is20Bit;
        branchType = `BNO;
        jmp = 0;
        memtoReg = 0;
        immSrc = 1;
        regWEN = 1;
        ALUop = `ALU_NO;
        memOp = `MEMNO;
        immShiftOp = `zero_fill;
        PCsrc = 0;
        memSize = `byteMem;
      end
      // U-type AUIPC : rd = pc + (imm << 12)
      7'b0010111: begin
        fct7 = 0;
        fct3 = 0;
        rd = instruction[11:7];
        rs1 = 0;
        rs2 = 0;
        imm = instruction[31:12];
        immBitWidth = `is20Bit;
        branchType = `BNO;
        jmp = 0;
        memtoReg = 0;
        immSrc = 1;
        regWEN = 1;
        ALUop = `ALU_ADD;
        memOp = `MEMNO;
        immShiftOp = `zero_fill;
        PCsrc = 1;
        memSize = `byteMem;
      end
      // J-type JAL JALR
      // TODO: consider : how to set control for PC+imm and place return address for the JAL / JLAR command
      7'b1101111: begin
        fct7 = 0;
        fct3 = instruction[14:12];
        rd = instruction[11:7];
        rs2 = 0;
        branchType = `BNO;
        jmp = 1;
        memtoReg = 0;
        immSrc = 1;
        regWEN = 1;
        ALUop = `ALU_ADD;
        memOp = `MEMNO;
        immBitWidth = `is20Bit;
        immShiftOp = `zero_fill;
        PCsrc = 1;
        memSize = `byteMem;
        if (fct3 == 3'b000) begin  // JLAR
          rs1 = instruction[19:15];
          imm = {{8'b0}, instruction[31:20]};
        end else begin
          rs1 = 0;
          imm = {instruction[31], instruction[19:12], instruction[20], instruction[30:21]};
        end
      end
      // B-type BEQ BNE BLT BGE
      7'b1100011: begin
        fct7 = 0;
        fct3 = instruction[14:12];
        rs1 = instruction[19:15];
        rs2 = instruction[24:20];
        rd = 0;
        immBitWidth = `is13Bit;
        imm = {{7'b0}, {instruction[31]}, instruction[7], instruction[30:26], instruction[11:7]};
        memOp = `MEMNO;
        jmp = 0;
        memtoReg = 0;
        immShiftOp = `no_shift;
        memSize = `byteMem;
        immSrc = 0;
        PCsrc = 0;
        regWEN = 0;
        case (fct3)
          3'b000: begin
            branchType = `BEQ;
            ALUop = `ALU_UCOMP;
          end
          3'b001: begin
            branchType = `BNE;
            ALUop = `ALU_UCOMP;
          end
          3'b100: begin
            branchType = `BLT;
            ALUopop = `ALU_SCOMP;
          end
          3'b101: begin
            branchType = `BGE;
            ALUopop = `ALU_SCOMP;
          end
          3'b110: begin
            branchType = `BLTU;
            ALUopop = `ALU_UCOMP;
          end
          3'b111: begin
            branchType = `BGEU;
            ALUopop = `ALU_UCOMP;
          end
          default: begin
            branchType = `BNO;
            ALUopop = `ALU_NO;
          end
        endcase
      end
    endcase
  end


endmodule
