// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VregisterFile.h for the primary calling header

#include "VregisterFile___024root.h"
#include "VregisterFile__Syms.h"

//==========


void VregisterFile___024root___ctor_var_reset(VregisterFile___024root* vlSelf);

VregisterFile___024root::VregisterFile___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VregisterFile___024root___ctor_var_reset(this);
}

void VregisterFile___024root::__Vconfigure(VregisterFile__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VregisterFile___024root::~VregisterFile___024root() {
}

void VregisterFile___024root___eval_initial(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VregisterFile___024root___settle__TOP__2(VregisterFile___024root* vlSelf);

void VregisterFile___024root___eval_settle(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___eval_settle\n"); );
    // Body
    VregisterFile___024root___settle__TOP__2(vlSelf);
}

void VregisterFile___024root___final(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___final\n"); );
}

void VregisterFile___024root___ctor_var_reset(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->dataIn = VL_RAND_RESET_Q(64);
    vlSelf->regWirteEN = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->outData1 = VL_RAND_RESET_Q(64);
    vlSelf->outData2 = VL_RAND_RESET_Q(64);
    vlSelf->readReg1 = VL_RAND_RESET_I(5);
    vlSelf->readReg2 = VL_RAND_RESET_I(5);
    vlSelf->writeReg = VL_RAND_RESET_I(5);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->registerFile__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
