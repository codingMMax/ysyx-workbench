`timescale 1ns / 1ps

`define ZeroWord 64'h00000000_00000000
`define PC_START   64'h00000000_80000000  
`define REG_BUS    63 : 0     
`define Imm_20     19:0

//define read bit-length
`define read_no   2'00 // no load operation required
`define read_byte 2'01 // load 8-bit data from memroy to reg
`define read_hw   2'10 // load 16-bit half-word data from memory to reg
`define read_fw   2'11 // load 32-bit full-word data from memory to reg

//define shift operation
`define no_shift 3'b000
`define sign_shift 3'b001
`define unsign_shift 3'b010
`define zero_fill 3'b011

//define ALU control signal
`define ALU_NO   4'b0000
`define ALU_SUB  4'b0001
`define ALU_ADD  4'b0010
`define ALU_AND  4'b0011
`define ALU_OR   4'b0100
`define ALU_XOR  4'b0101
`define ALU_RAS  4'b0110 // right arithematci shift
`define ALU_RLS  4'b0111 // right logic shift
`define ALU_LAS  4'b1000 // left arithemtic shift
`define ALU_LLS  4'b1001 // left logic shift
`define ALU_SCOMP 4'b1010 // compare the input 2 data as signed digits
`define ALU_UCOMP 4'b1011 // compare the input 2 data as unsigned digits
