`include "defines.v"

module immGenerator(
    input[`Imm_20] imm,
    input [2:0] shiftOp,
    input is12Bit,
    output [63:0] shiftImm
);
always @(* ) begin // combinational logic

    case(shiftOp)
    `no_shift: shiftImm = 0;
    `sign_shift:  begin 
        if(is12Bit == 1) // only first 12-bit is valid
        shiftImm = {{52{imm[19]}},imm[19:8]};
        else
        shiftImm = {{44{imm[19]}},imm};
    end
    `unsign_shift:  begin 
        if(is12Bit == 1) // only first 12-bit is valid
        shiftImm = {{52{imm[19]}},imm[19:8]};
        else
        shiftImm = {{52'b0},imm};
    end
    `zero_fill:  shiftImm = {imm,{44'b0}}; 

    default:
    shiftImm = 1;
    endcase
end

endmodule
