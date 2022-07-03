// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VregisterFile.h for the primary calling header

#ifndef VERILATED_VREGISTERFILE___024ROOT_H_
#define VERILATED_VREGISTERFILE___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VregisterFile__Syms;
class VregisterFile_VerilatedVcd;


//----------

VL_MODULE(VregisterFile___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(regWirteEN,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(readReg1,4,0);
    VL_IN8(readReg2,4,0);
    VL_IN8(writeReg,4,0);
    VL_IN64(dataIn,63,0);
    VL_OUT64(outData1,63,0);
    VL_OUT64(outData2,63,0);

    // LOCAL SIGNALS
    VlUnpacked<QData/*63:0*/, 32> registerFile__DOT__regs;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VregisterFile__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VregisterFile___024root);  ///< Copying not allowed
  public:
    VregisterFile___024root(const char* name);
    ~VregisterFile___024root();

    // INTERNAL METHODS
    void __Vconfigure(VregisterFile__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
