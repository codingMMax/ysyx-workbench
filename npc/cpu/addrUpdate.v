`include "defines.v"
/* verilator lint_off BLKSEQ */
module addrUpdate (
input clk,
input wire[`REG_BUS] pcAddr,
input wire[`REG_BUS] imm,
input wire jmp,
output reg [`REG_BUS] outAddr,
reg [`REG_BUS] defaultAddr,
reg [`REG_BUS] immAddr
);
/*Combinational Logic requires blocking assignment*/
always @(posedge clk ) begin
    defaultAddr = pcAddr + 4;
    immAddr  = ((imm << 1) + pcAddr);
    if(jmp == 1) begin
        assign outAddr = immAddr;
    end
    else begin
        assign outAddr = defaultAddr;
    end      
end
endmodule
