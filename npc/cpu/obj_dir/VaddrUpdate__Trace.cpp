// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VaddrUpdate__Syms.h"


void VaddrUpdate___024root__traceChgSub0(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep);

void VaddrUpdate___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VaddrUpdate___024root* const __restrict vlSelf = static_cast<VaddrUpdate___024root*>(voidSelf);
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VaddrUpdate___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VaddrUpdate___024root__traceChgSub0(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->clk));
        tracep->chgQData(oldp+1,(vlSelf->pcAddr),64);
        tracep->chgQData(oldp+3,(vlSelf->imm),64);
        tracep->chgBit(oldp+5,(vlSelf->jmp));
        tracep->chgQData(oldp+6,(vlSelf->outAddr),64);
        tracep->chgQData(oldp+8,(vlSelf->defaultAddr),64);
        tracep->chgQData(oldp+10,(vlSelf->immAddr),64);
    }
}

void VaddrUpdate___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    VaddrUpdate___024root* const __restrict vlSelf = static_cast<VaddrUpdate___024root*>(voidSelf);
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
