`include "defines.v"
`include "mainController.v"
module decoder (input clk,
                input [`REG_BUS] instruction,
                output validIns;
                output [6:0] opcode,
                output [4:0] rs1,
                output [4:0] rs2,
                output [4:0] rd,
                output [`Imm_20] imm,
                );
    reg [6:0]fct7;
    reg [2:0]fct3;
    opcode = instruction[6:0];
    always @(posedge clk) begin
        case (opcode)
            7'b0110011: // R-Type add,xor,or,and,sub,sll,slt,sltu,srl,sra
            begin
                fct7 = instruction[31:25];
                fct3 = instruction[14:12];
                rd   = instruction[11:6];
                rs1  = instruction[19:15];
                rs2  = instruction[24:20];
                imm  = 0;
            end
            7'b0010011: // I-Type addi,slti,sltu,xori,ori,andi
            begin
                fct7 = 0;
                fct3 = instruction[14:12];
                rd   = instruction[11:6];
                rs1  = instruction[19:15];
                rs2  = 0;
                imm  = {0,instruction[31:20]};
            end
            7'b0000011:// I-Type load,LB,LH,LW,LBU,LHU
            begin
                fct7 = 0;
                fct3 = instruction[14:12];
                rd   = instruction[11:6];
                rs1  = instruction[19:15];
                rs2  = 0;
                imm  = {0,instruction[31:20]}
            end
            7'b0110111:// U-Type LUI
            begin
                fct7 = 0;
                fct3 = 0;
                rd   = instruction[11:6];
                rs1  = 0;
                rs2  = 0;
                imm  = {0,instruction[31:12]}
            end
            7'b0010111:// U-Type AUIPC
            begin
                fct7 = 0;
                fct3 = 0;
                rd   = instruction[11:6];
                rs1  = 0;
                rs2  = 0;
                imm  = {0,instruction[31:12]}
            end
            7'b1101111:// J-type JAL
            begin
                fct7 = 0;
                fct3 = 0;
                rd   = instruction[11:6];
                rs1  = 0;
                rs2  = 0;
                imm = {0,instruction[20],instruction[10:1],instruction[11],instruction[19:12]};
            end
            default:
        endcase
    end
    
endmodule
    

