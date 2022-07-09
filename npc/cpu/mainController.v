`include "defines.v"
    //assign rd and imm value based on the opcodes
module mainController(
        input [6:0] OPcode,
        input clock,
        output MainValidIns,
        output [3:0] MainALUop,
        output MainisSrcImm,
        output MainregWrite,
        output MainmemtoReg,
        output Mainbranch,
        output [1:0] MainmemRead,
        output MainmemWrite,
        output [2:0] MainshiftOps,
        );
always @(posedge clock) begin
    case (opcode)
        7'b0110011: // R-Type add,xor,or,and,sub,sll,slt,sltu,srl,sra
        begin
            MainValidIns = 1;
            loadUpper20Rd = 0;
            MainisSrcImm = 0;
            MainregWrite = 1;
            Mainbranch = 0;
            MainmemRead = 0;
            MainmemWrite = 0;
            MainmemtoReg = `load_no;
            MainshiftOps = `no_shift;
            case(fct7) 
            7'b0100000: begin// sub or sra
                case(fct3)
                    3'b000:  MainALUop = `ALU_SUB; // sub
                    3'b101:  MainALUop = `ALU_RAS; // sra
                endcase
            end
            7'b0000000: begin // ADD SLTU OR SLL XOR AND SLT SRL
                case(fct3)
                3'b000: MainALUop = `ALU_ADD;  // ADD
                3'b001: MainALUop = `ALU_LLS;  // SLL
                3'b010: MainALUop = `ALU_SCOMP; // SLT
                3'b011: MainALUop = `ALU_UCOMP; //SLTU
                3'b100: MainALUop = `ALU_XOR; // XOR
                3'b101: MainALUop = `ALU_RLS; //SRL
                3'b110: MainALUop = `ALU_OR; //OR
                3'b111: MainALUop = `ALU_AND; //AND
                endcase
            end
            default:
            validIns = 0;
            endcase
        end
        7'b0010011: // I-Type addi,slti,sltu,xori,ori,andi
        begin
            MainValidIns = 1;
            loadUpper20Rd = 0;
            MainisSrcImm = 1;
            MainregWrite = 1;
            Mainbranch   = 0;
            MainmemRead  = `read_no;
            MainmemWrite = 0;
            MainmemtoReg = 0;
            MainshiftOps = `sign_shift;
            case(fct3) 
            3'b000: MainALUop = `ALU_ADD; // addi
            3'b010: MainALUop = `ALU_SCOMP;// slti
            3'b011: begin MainALUop = `ALU_UCOMP; shiftOp = `unsign_shift; end // sltiu
            3'b100: MainALUop = `ALU_XOR; // xori
            3'b110: MainALUop = `ALU_OR; // ori
            3'b111: MainALUop = `ALU_AND; // andi
            default:
            validIns = 0;
            endcase
        end
        7'b0000011:// I-Type load,LB,LH,LW,LBU,LHU
        begin
            MainValidIns = 1;
            loadUpper20Rd = 0;
            MainisSrcImm = 1;
            MainregWrite = 1;
            Mainbranch   = 0;
            MainmemtoReg = 1;
            MainmemWrite = 0;
            MainALUop = `ALU_NO; //load operation no arithematic required
            MainshiftOps = `sign_shift;
            case(fct3)
            3'b000: MainmemRead = `read_byte; // lb
            3'b001: MainmemRead = `read_hw; // lh
            3'b010: MainmemRead = `read_fw; // lw
            3'b100: begin MainmemRead = `read_byte; MainshiftOps = `unsign_shift; end // unsgined shift LBU
            3'b101: begin MainmemRead = `read_hw;   MainshiftOps = `unsign_shift; end // unsigned shift LHU
            default:
            validIns = 0;
            endcase
        end
        7'b0110111:// U-Type LUI
        begin
            MainValidIns = 1;
            MainisSrcImm = 1;
            MainregWrite = 1;
            Mainbranch   = 0;
            MainmemtoReg = 0;
            MainmemWrite = 0;
            MainALUop = `ALU_NO; //load operation no arithematic required
            MainshiftOps = `zero_fill;
        end
        7'b0010111:// U-Type AUIPC
        begin
            MainValidIns = 1;
            MainisSrcImm = 1;
            MainregWrite = 1;
            Mainbranch   = 0;
            MainmemtoReg = 0;
            MainmemWrite = 0;
            MainALUop = `ALU_ADD; 
            MainshiftOps = `zero_fill;// add the PC address with zero-filled immediate value
        end
        7'b1101111:// J-type JAL
        begin
            MainValidIns = 1;
            MainisSrcImm = 1;
            MainregWrite = 1;
            Mainbranch   = 1;
            MainmemtoReg = 0;
            MainmemWrite = 0;
            MainALUop = `ALU_ADD; 
            MainshiftOps = `no_shift;
        end
        default:
        validIns = 0;
    endcase
    end
endmodule