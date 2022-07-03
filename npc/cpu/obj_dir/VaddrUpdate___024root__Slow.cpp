// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VaddrUpdate.h for the primary calling header

#include "VaddrUpdate___024root.h"
#include "VaddrUpdate__Syms.h"

//==========


void VaddrUpdate___024root___ctor_var_reset(VaddrUpdate___024root* vlSelf);

VaddrUpdate___024root::VaddrUpdate___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VaddrUpdate___024root___ctor_var_reset(this);
}

void VaddrUpdate___024root::__Vconfigure(VaddrUpdate__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VaddrUpdate___024root::~VaddrUpdate___024root() {
}

void VaddrUpdate___024root___eval_initial(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___eval_initial\n"); );
}

void VaddrUpdate___024root___combo__TOP__1(VaddrUpdate___024root* vlSelf);

void VaddrUpdate___024root___eval_settle(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___eval_settle\n"); );
    // Body
    VaddrUpdate___024root___combo__TOP__1(vlSelf);
}

void VaddrUpdate___024root___final(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___final\n"); );
}

void VaddrUpdate___024root___ctor_var_reset(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->pcAddr = VL_RAND_RESET_Q(64);
    vlSelf->imm = VL_RAND_RESET_Q(64);
    vlSelf->jmp = VL_RAND_RESET_I(1);
    vlSelf->outAddr = VL_RAND_RESET_Q(64);
    vlSelf->defaultAddr = VL_RAND_RESET_Q(64);
    vlSelf->immAddr = VL_RAND_RESET_Q(64);
}
