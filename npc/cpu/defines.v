
`timescale 1ns / 1ps

`define RISCV_PRIV_MODE_U 0
`define RISCV_PRIV_MODE_S 1
`define RISCV_PRIV_MODE_M 3

`define ZeroWord 64'h00000000_00000000
`define PC_START 64'h00000000_80000000  
`define REG_BUS 63 : 0    
`define INS_BUS 31 : 0 
`define Imm_20 19:0

// memory read/load  MemWrite
`define MEMS 2'b11 // memory store
`define MEMLU 2'b10 // memory load unsigned
`define MEML 2'b01 //memory load signed
`define MEMNO 2'b00 //memory no operation

//define memory bit-length
`define byteMem 2'b00 // no load operation required
`define hwMem 2'b01 // load 16-bit data from memroy to reg
`define fwMem 2'b10 // load 32-bit half-word data from memory to reg
`define dwMem 2'b11 // load 64-bit full-word data from memory to reg

//define shift operation
`define no_shift 3'b000   // no immediate number
`define sign_shift 3'b001 // signed shift to make it 64-bit width
`define unsign_shift 3'b010 // unsigned shift to make it 64-bit width
`define zero_fill 3'b011 // place the 20-bit instruction in the first 20-bit  and zero-fill the rest bits

//define the immediate bit width
`define noBit 2'b00
`define is20Bit 2'b01
`define is13Bit 2'b10
`define is12Bit 2'b11

//define branch control sigal
`define BNO 3'b000 // no branch is taken
`define BEQ 3'b001 // take the branch if ALU rs1 == rs2
`define BNE 3'b010 // take the branch if ALU rs1 != rs2
`define BLT 3'b011 // take the branch if ALU rs1 < rs2 signed compare
`define BGE 3'b100 // take the branch if ALU rs1 > rs2 signed compare
`define BLTU 3'b101 // take the branch if ALU rs1 < rs2 unsigned compare
`define BGEU 3'b110 // take the branch if ALU rs1 > rs2 unsigned compare

//define the SLT STLU SLTI SLTIU
`define SLNO = 3'b000
`define SLT = 3'b001
`define SLTU = 3'b010
`define SLTI = 3'b011
`define SLTIU = 3'b100

//define ALU control signal
`define ALU_NO 4'b0000
`define ALU_SUB 4'b0001
`define ALU_ADD 4'b0010
`define ALU_AND 4'b0011
`define ALU_OR 4'b0100
`define ALU_XOR 4'b0101
`define ALU_SAR 4'b0110 // right arithematci shift
`define ALU_SLR 4'b0111 // right logic shift
`define ALU_SLL 4'b1000 // left logic shift
`define ALU_SCOMP 4'b1001 // compare the input 2 data as signed digits
`define ALU_UCOMP 4'b1010 // compare the input 2 data as unsigned digits

