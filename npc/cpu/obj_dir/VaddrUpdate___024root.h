// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VaddrUpdate.h for the primary calling header

#ifndef VERILATED_VADDRUPDATE___024ROOT_H_
#define VERILATED_VADDRUPDATE___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VaddrUpdate__Syms;
class VaddrUpdate_VerilatedVcd;


//----------

VL_MODULE(VaddrUpdate___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(jmp,0,0);
    VL_IN64(pcAddr,63,0);
    VL_IN64(imm,63,0);
    VL_OUT64(outAddr,63,0);
    VL_OUT64(defaultAddr,63,0);
    VL_OUT64(immAddr,63,0);

    // INTERNAL VARIABLES
    VaddrUpdate__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VaddrUpdate___024root);  ///< Copying not allowed
  public:
    VaddrUpdate___024root(const char* name);
    ~VaddrUpdate___024root();

    // INTERNAL METHODS
    void __Vconfigure(VaddrUpdate__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
