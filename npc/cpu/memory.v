`include "defines.v"
module memory (
    input clk,
    input rst,
    input rEN, // read data enable
    input wEN, // write data enable
    input [`REG_BUS] wdata, // wrie data bus
    input [`REG_BUS] wmask, // write data mask
    input [19:0] memoffsetImm, // 20-bit read memory offset
    input [1:0] memOp, // memory operation types
    input [1:0] memSize, // memory write/load size defines the write mask port
    input [`REG_BUS] addr,// memory address 
    output [`REG_BUS] memData, // output read data

);
// load value from memory and shift/extend to XLEN bits before storing into register

always@(posedge clk) begin


end



// store value from register and shift/extend to XLEN bits before storing into memory



endmodule
