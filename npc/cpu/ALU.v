`include "defines.v"
/* verilator lint_off PINMISSING */
module ALU (
input clk,
input reg[31:0] instruction,
input reg[63:0] data1,
input reg[63:0] data2,
input reg[63:0] imm,
input reg[1:0] OPfromMainControl,
output reg isZero,
output reg[63:0] result
);
reg [3:0] Optype;
reg ALUsrc;

/*instantiate the control module*/
ALUcontrol control(.instruction(instruction),.ALUopFromMain(OPfromMainControl),.clk(clk),.ALUopType(Optype),.immSrc(ALUsrc));
reg[63:0] selectData;
always@(posedge clk) begin
    
    selectData = ((ALUsrc == 1) ? imm:data2);
    case(Optype)
    4'b0010: result = data1 + selectData; // add
    4'b0110: result = data1 - selectData; // subtract
    4'b0000: result = data1 & selectData; // AND
    4'b0001: result = data1 | selectData; // OR
    default:
    result = `ZeroWord;
endcase
    isZero = (result == 0)? 1:0;
end
endmodule

module ALUcontrol(
    input reg[31:0] instruction,
    input reg[1:0] ALUopFromMain,
    input clk,
    output [3:0] ALUopType,
    output reg immSrc
);
/*splite the 30-bit and fct3 domian*/
reg [3:0]inst30fct3;
reg [6:0]regType;
always@(posedge clk) begin
    inst30fct3[3] = instruction[30];
    inst30fct3[2:0] = instruction[14:12];
    regType = instruction[6:0];
    case(regType)
    7'b0110011: immSrc = 0; // R-type
    7'b0010011: immSrc = 1; // I-type
    default:
    immSrc = 1;
    endcase
    case (ALUopFromMain)
        2'b00:  ALUopType = 4'b0010; 
        2'b01:  ALUopType = 4'b0110; 
        2'b10: begin
            immSrc = 0;
            case(inst30fct3) 
            4'b0000:  ALUopType = 4'b0010;
            4'b1000:  ALUopType = 4'b0110;
            4'b0111:  ALUopType = 4'b0000;
            4'b0110:  ALUopType = 4'b0001;
            default:
            ALUopType = 4'b1111;
        endcase
        end 
        default: 
        ALUopType = 4'b1111;
    endcase
end
endmodule
