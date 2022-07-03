`include "defines.v"

module ProgramCounter (
input wire[`REG_BUS] inAddr;
output reg[`REG_BUS] outAddr;
input clk,en,reset;
);
always @(posedge clk) begin
    if(en == 1)
    outAddr <= inAddr;
    else if (reset == 1)
    outAddr <= 'PC_START;
end
     
endmodule