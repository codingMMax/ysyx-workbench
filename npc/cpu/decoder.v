`include "defines.v"
/* verilator lint_off UNUSED */
module decoder (
                input [`INS_BUS] instruction,
                output reg validIns,
                output reg [6:0] opcode,
                output reg [4:0] rs1,
                output reg [4:0] rs2,
                output reg [4:0] rd,
                output reg [`Imm_20] imm,
                output is12Bit // if the imm is a 12-bit imm
                );
    reg [6:0]fct7;
    reg [2:0]fct3;
    always @(*) begin // combinational logic
        opcode = instruction[6:0];
        case (opcode)
            7'b0110011: // R-Type add,xor,or,and,sub,sll,slt,sltu,srl,sra
            begin
                validIns = 1;
                fct7 = instruction[31:25];
                fct3 = instruction[14:12];
                rd   = instruction[11:7];
                rs1  = instruction[19:15];
                rs2  = instruction[24:20];
                imm  = 0;
                is12Bit = 0;
            end
            7'b0010011: // I-Type addi,slti,sltu,xori,ori,andi
            begin
                validIns = 1;
                fct7 = 0;
                fct3 = instruction[14:12];
                rd   = instruction[11:7];
                rs1  = instruction[19:15];
                rs2  = 0;
                imm  = {instruction[31:20],{8'b0}};
                is12Bit = 1; // 12-bit valid imm
            end
            7'b0000011:// I-Type load,LB,LH,LW,LBU,LHU
            begin
                validIns = 1;
                validIns = 1;
                fct7 = 0;
                fct3 = instruction[14:12];
                rd   = instruction[11:7];
                rs1  = instruction[19:15];
                rs2  = 0;
                imm  = {instruction[31:20],{8'b0}};
                is12Bit = 1; // 12-bit valid imm
            end
            7'b0110111:// U-Type LUI
            begin
                validIns = 1;
                validIns = 1;
                validIns = 1;
                fct7 = 0;
                fct3 = 0;
                rd   = instruction[11:7];
                rs1  = 0;
                rs2  = 0;
                imm  = instruction[31:12];
                is12Bit = 0; // 20-bit imm
            end
            7'b0010111:// U-Type AUIPC
            begin
                validIns = 1;
                fct7 = 0;
                fct3 = 0;
                rd   = instruction[11:7];
                rs1  = 0;
                rs2  = 0;
                imm  = instruction[31:12];
                is12Bit = 0;

            end
            7'b1101111:// J-type JAL
            begin
                validIns = 1;
                fct7 = 0;
                fct3 = 0;
                rd   = instruction[11:7];
                rs1  = 0;
                rs2  = 0;
                imm = {instruction[31],instruction[19:12],instruction[20],instruction[30:21]};
                is12Bit = 0;
            end
            default:
            begin
            validIns = 0;
            opcode = 0;
            rs1 = 0;
            rs2 = 0;
            rd = 0;
            imm = 0;
            is12Bit = 0;
            fct7 = 0;
            fct3 = 0;
            end
        endcase
    end
    
endmodule
    

