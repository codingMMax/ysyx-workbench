`include "defines.v"
/* verilator lint_off PINMISSING */
module ALU (
input [`REG_BUS] data1,
input [`REG_BUS] data2,
input [`REG_BUS] imm,
input immSrc,
input [3:0] ALUop,
output reg isZero,
output reg[63:0] result
);
reg [`REG_BUS]shift_right_1_r;
reg [`REG_BUS]shift_right_2_r;
reg [`REG_BUS]shift_right_4_r;
reg [`REG_BUS]shift_right_8_r;
reg [`REG_BUS]shift_right_16_r;
reg [`REG_BUS]shift_right_32_r;


reg [`REG_BUS]shift_left_1_r;
reg [`REG_BUS]shift_left_2_r;
reg [`REG_BUS]shift_left_4_r;
reg [`REG_BUS]shift_left_8_r;
reg [`REG_BUS]shift_left_16_r;
reg [`REG_BUS]shift_left_32_r;



always @(*) begin
    /** assign initial values to regs**/
    reg[`REG_BUS] muxOut = ((immSrc == 1)? imm : data2);
    isZero = 1'b0;
    shift_right_1_r = 64'b0;
    shift_right_2_r = 64'b0;
    shift_right_4_r = 64'b0;
    shift_right_8_r = 64'b0;
    shift_right_16_r = 64'b0;
    shift_right_32_r = 64'b0;
    shift_left_1_r = 64'b0;
    shift_left_2_r = 64'b0;
    shift_left_4_r = 64'b0;
    shift_left_8_r = 64'b0;
    shift_left_16_r = 64'b0;
    shift_left_32_r = 64'b0;
    case(ALUop)
        `ALU_NO: result = data1;
        `ALU_ADD: result = data1 + muxOut;
        `ALU_OR:  result = data1 | muxOut;
        `ALU_AND: result = data1 & muxOut;
        `ALU_XOR: result = data1 ^ muxOut;
        //compare two input in signed format
        `ALU_SCOMP: result = ($signed(data1) < ($signed(data2))? data1 : 0) ;
        //compare two input in unsigned format
        `ALU_UCOMP: result = ((data1  < data2)? data1 : 0);
        // logic left shift
        `ALU_SLL: begin  
            if(data2[0] == 1) shift_left_1_r = {data1[62:0],1'b0};
                    else shift_left_1_r = data1;
            if(data2[1] == 1) shift_left_2_r = {shift_left_1_r[61:0],2'b0};
                    else shift_left_2_r = shift_left_1_r;
            if(data2[2] == 1) shift_left_4_r = {shift_left_2_r[59:0],4'b0};
                    else shift_left_4_r = shift_left_2_r;
            if(data2[3] == 1) shift_left_8_r = {shift_left_4_r[55:0],8'b0};
                    else shift_left_8_r = shift_left_4_r; 
            if(data2[4] == 1) shift_left_16_r = {shift_left_8_r[47:0],16'b0};
                    else shift_left_16_r = shift_left_8_r;
            if(data2[4] == 1) shift_left_32_r = {shift_left_16_r[31:0],32'b0};
                    else shift_left_32_r = shift_left_16_r;
                    result = shift_left_32_r;
                end
        // arithematic right shift
        `ALU_SAR: begin
            if(data2[0] == 1) shift_right_1_r = {{1{data1[63]}},data1[63:1]};
                    else shift_right_1_r = data1;
            if(data2[1] == 1) shift_right_2_r = {{2{data1[63]}},shift_right_1_r[63:2]};
                    else shift_right_2_r = shift_right_1_r;
            if(data2[2] == 1) shift_right_4_r = {{4{data1[63]}},shift_right_2_r[63:4]};
                    else shift_right_4_r = shift_right_2_r;
            if(data2[3] == 1) shift_right_8_r = {{8{data1[63]}},shift_right_4_r[63:8]};
                    else shift_right_8_r = shift_right_4_r; 
            if(data2[4] == 1) shift_right_16_r = {{16{data1[63]}},shift_right_8_r[63:16]};
                    else shift_right_16_r = shift_right_8_r;
            if(data2[4] == 1) shift_right_32_r = {{32{data1[63]}},shift_right_16_r[63:32]};
                    else shift_right_32_r = shift_right_16_r;  
                    result = shift_right_32_r;
        end
        // logic right shift
        `ALU_SLR: begin
            if(data2[0] == 1) shift_right_1_r = {1'b0,data1[63:1]};
                    else shift_right_1_r = data1;
            if(data2[1] == 1) shift_right_2_r = {2'b0,shift_right_1_r[63:2]};
                    else shift_right_2_r = shift_right_1_r;
            if(data2[2] == 1) shift_right_4_r = {4'b0,shift_right_2_r[63:4]};
                    else shift_right_4_r = shift_right_2_r;
            if(data2[3] == 1) shift_right_8_r = {8'b0,shift_right_4_r[63:8]};
                    else shift_right_8_r = shift_right_4_r; 
            if(data2[4] == 1) shift_right_16_r = {16'b0,shift_right_8_r[63:16]};
                    else shift_right_16_r = shift_right_8_r;
            if(data2[4] == 1) shift_right_32_r = {32'b0,shift_right_16_r[63:32]};
                    else shift_right_32_r = shift_right_16_r;
                    result = shift_right_32_r;
        end
        `ALU_SUB:begin
            result = data1 - data2;
            if(result == 0) isZero = 1;
            else isZero = 0;
        end
        default:
        begin
        isZero = 0;
        result = 0;

        end
    endcase

end



endmodule

