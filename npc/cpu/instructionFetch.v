`include "defines.v"
module instructionFetch (
    input jmp,
    input clock,
    input rst,
    input [`REG_BUS] addrOffset,
    input branch,
    output PC,
    output [`INS_BUS] instruction
);
  wire [`REG_BUS] insAddr;
  parameter START_ADDR = `PC_START - 4;

  always @(posedge clock) begin
    if (rst) PC <= START_ADDR;
    else begin
      if (jmp || branch) PC <= (addrOffset + PC);
      else PC <= PC + 4;
    end
  end
  // Access memory
  reg [63:0] rdata;
  RAMHelper RAMHelper (
      .clk  (clock),
      .en   (1),
      .rIdx ((pc - `PC_START) >> 3),
      .rdata(rdata),
      .wIdx (0),
      .wdata(0),
      .wmask(0),
      .wen  (0)
  );
  assign inst = pc[2] ? rdata[63 : 32] : rdata[31 : 0];

endmodule
