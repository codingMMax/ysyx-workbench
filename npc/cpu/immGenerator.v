`include "defines.v"

module immGenerator (
    input [`Imm_20] imm,
    input [2:0] shiftOp,
    input immbitWidth,
    output reg [63:0] shiftImm
);
  always @(* ) begin  // combinational logic

    case (shiftOp)
      `no_shift:  shiftImm = 0;
      `sign_shift: begin
        case (immbitWidth)
          `is20Bit: shiftImm = {{44{imm[19]}}, imm};
          `is13Bit: shiftImm = {{51{imm[12]}}, imm[12:0]};
          `is12Bit: shiftImm = {{52{imm[11]}}, imm[11:0]};
        endcase
      end
      `unsign_shift: begin
        case (immbitWidth)
          `is20Bit: shiftImm = {44'b0, imm};
          `is13Bit: shiftImm = {51'b0, imm[12:0]};
          `is12Bit: shiftImm = {52'b0, imm[11:0]};
        endcase
      end
      `zero_fill: shiftImm = {imm, {44'b0}};

      default: shiftImm = 1;
    endcase
  end

endmodule
