// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VaddrUpdate.h for the primary calling header

#include "VaddrUpdate___024root.h"
#include "VaddrUpdate__Syms.h"

//==========

VL_INLINE_OPT void VaddrUpdate___024root___combo__TOP__1(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->defaultAddr = (4ULL + vlSelf->pcAddr);
    vlSelf->immAddr = ((vlSelf->imm << 1U) + vlSelf->pcAddr);
    vlSelf->outAddr = ((IData)(vlSelf->jmp) ? vlSelf->immAddr
                        : vlSelf->defaultAddr);
}

void VaddrUpdate___024root___eval(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___eval\n"); );
    // Body
    VaddrUpdate___024root___combo__TOP__1(vlSelf);
}

QData VaddrUpdate___024root___change_request_1(VaddrUpdate___024root* vlSelf);

VL_INLINE_OPT QData VaddrUpdate___024root___change_request(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___change_request\n"); );
    // Body
    return (VaddrUpdate___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VaddrUpdate___024root___change_request_1(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VaddrUpdate___024root___eval_debug_assertions(VaddrUpdate___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddrUpdate___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->jmp & 0xfeU))) {
        Verilated::overWidthError("jmp");}
}
#endif  // VL_DEBUG
