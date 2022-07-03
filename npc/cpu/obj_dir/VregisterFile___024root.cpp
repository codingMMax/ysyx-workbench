// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VregisterFile.h for the primary calling header

#include "VregisterFile___024root.h"
#include "VregisterFile__Syms.h"

//==========

VL_INLINE_OPT void VregisterFile___024root___sequent__TOP__1(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___sequent__TOP__1\n"); );
    // Variables
    CData/*0:0*/ __Vdlyvset__registerFile__DOT__regs__v0;
    CData/*4:0*/ __Vdlyvdim0__registerFile__DOT__regs__v32;
    CData/*0:0*/ __Vdlyvset__registerFile__DOT__regs__v32;
    QData/*63:0*/ __Vdlyvval__registerFile__DOT__regs__v32;
    // Body
    __Vdlyvset__registerFile__DOT__regs__v0 = 0U;
    __Vdlyvset__registerFile__DOT__regs__v32 = 0U;
    if (vlSelf->rst) {
        __Vdlyvset__registerFile__DOT__regs__v0 = 1U;
    } else if (((IData)(vlSelf->regWirteEN) & (0U != (IData)(vlSelf->writeReg)))) {
        __Vdlyvval__registerFile__DOT__regs__v32 = vlSelf->dataIn;
        __Vdlyvset__registerFile__DOT__regs__v32 = 1U;
        __Vdlyvdim0__registerFile__DOT__regs__v32 = vlSelf->writeReg;
    }
    if (__Vdlyvset__registerFile__DOT__regs__v0) {
        vlSelf->registerFile__DOT__regs[0U] = 0ULL;
        vlSelf->registerFile__DOT__regs[1U] = 0ULL;
        vlSelf->registerFile__DOT__regs[2U] = 0ULL;
        vlSelf->registerFile__DOT__regs[3U] = 0ULL;
        vlSelf->registerFile__DOT__regs[4U] = 0ULL;
        vlSelf->registerFile__DOT__regs[5U] = 0ULL;
        vlSelf->registerFile__DOT__regs[6U] = 0ULL;
        vlSelf->registerFile__DOT__regs[7U] = 0ULL;
        vlSelf->registerFile__DOT__regs[8U] = 0ULL;
        vlSelf->registerFile__DOT__regs[9U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0xaU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0xbU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0xcU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0xdU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0xeU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0xfU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x10U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x11U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x12U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x13U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x14U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x15U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x16U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x17U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x18U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x19U] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x1aU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x1bU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x1cU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x1dU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x1eU] = 0ULL;
        vlSelf->registerFile__DOT__regs[0x1fU] = 0ULL;
    }
    if (__Vdlyvset__registerFile__DOT__regs__v32) {
        vlSelf->registerFile__DOT__regs[__Vdlyvdim0__registerFile__DOT__regs__v32] 
            = __Vdlyvval__registerFile__DOT__regs__v32;
    }
}

VL_INLINE_OPT void VregisterFile___024root___settle__TOP__2(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___settle__TOP__2\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->outData1 = 0ULL;
        vlSelf->outData2 = 0ULL;
    } else {
        vlSelf->outData1 = ((0U == (IData)(vlSelf->readReg1))
                             ? 0ULL : vlSelf->registerFile__DOT__regs
                            [vlSelf->readReg1]);
        vlSelf->outData2 = ((0U == (IData)(vlSelf->readReg2))
                             ? 0ULL : vlSelf->registerFile__DOT__regs
                            [vlSelf->readReg2]);
    }
}

void VregisterFile___024root___eval(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VregisterFile___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    VregisterFile___024root___settle__TOP__2(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VregisterFile___024root___change_request_1(VregisterFile___024root* vlSelf);

VL_INLINE_OPT QData VregisterFile___024root___change_request(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___change_request\n"); );
    // Body
    return (VregisterFile___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VregisterFile___024root___change_request_1(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VregisterFile___024root___eval_debug_assertions(VregisterFile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VregisterFile___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->regWirteEN & 0xfeU))) {
        Verilated::overWidthError("regWirteEN");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->readReg1 & 0xe0U))) {
        Verilated::overWidthError("readReg1");}
    if (VL_UNLIKELY((vlSelf->readReg2 & 0xe0U))) {
        Verilated::overWidthError("readReg2");}
    if (VL_UNLIKELY((vlSelf->writeReg & 0xe0U))) {
        Verilated::overWidthError("writeReg");}
}
#endif  // VL_DEBUG
