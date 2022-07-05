`include "defines.v"
module registerFile (
input [`REG_BUS] dataIn,
input regWirteEN,
input rst,
input clk,
output reg [`REG_BUS] outData1,
output reg [`REG_BUS] outData2,
input wire [4:0] readReg1,
input wire [4:0] readReg2,
input wire [4:0] writeReg
);
reg[`REG_BUS] regs[31:0];
/* reset and write inner registers*/
always @(posedge clk) begin
    if(rst == 1)begin
    regs[ 0] <= `ZeroWord;
    regs[ 1] <= `ZeroWord;
    regs[ 2] <= `ZeroWord;
    regs[ 3] <= `ZeroWord;
    regs[ 4] <= `ZeroWord;
    regs[ 5] <= `ZeroWord;
    regs[ 6] <= `ZeroWord;
    regs[ 7] <= `ZeroWord;
    regs[ 8] <= `ZeroWord;
    regs[ 9] <= `ZeroWord;
    regs[10] <= `ZeroWord;
    regs[11] <= `ZeroWord;
    regs[12] <= `ZeroWord;
    regs[13] <= `ZeroWord;
    regs[14] <= `ZeroWord;
    regs[15] <= `ZeroWord;
    regs[16] <= `ZeroWord;
    regs[17] <= `ZeroWord;
    regs[18] <= `ZeroWord;
    regs[19] <= `ZeroWord;
    regs[20] <= `ZeroWord;
    regs[21] <= `ZeroWord;
    regs[22] <= `ZeroWord;
    regs[23] <= `ZeroWord;
    regs[24] <= `ZeroWord;
    regs[25] <= `ZeroWord;
    regs[26] <= `ZeroWord;
    regs[27] <= `ZeroWord;
    regs[28] <= `ZeroWord;
    regs[29] <= `ZeroWord;
    regs[30] <= `ZeroWord;
    regs[31] <= `ZeroWord;
    end
    else begin
        if((regWirteEN == 1) && (writeReg != 0))begin
            regs[writeReg] <= dataIn;
        end
    end
end
/*Register File read and write sequencial logic and combinational logic?*/
// which part is seuqencial which part is combinational ? will the combinational and sequencial lead to race condition ?
/*read and output logics*/
always@(*)
begin
if(rst == 1) 
    begin
    outData1 = `ZeroWord;
    outData2 = `ZeroWord;
    end
 else  begin
    assign outData1 = ((readReg1 == 0) ? `ZeroWord:regs[readReg1]);
    assign outData2 = ((readReg2 == 0) ? `ZeroWord:regs[readReg2]);
 end

end

endmodule
