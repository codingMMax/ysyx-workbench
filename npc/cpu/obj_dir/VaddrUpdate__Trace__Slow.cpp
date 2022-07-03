// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VaddrUpdate__Syms.h"


void VaddrUpdate___024root__traceInitSub0(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VaddrUpdate___024root__traceInitTop(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VaddrUpdate___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VaddrUpdate___024root__traceInitSub0(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declQuad(c+2,"pcAddr", false,-1, 63,0);
        tracep->declQuad(c+4,"imm", false,-1, 63,0);
        tracep->declBit(c+6,"jmp", false,-1);
        tracep->declQuad(c+7,"outAddr", false,-1, 63,0);
        tracep->declQuad(c+9,"defaultAddr", false,-1, 63,0);
        tracep->declQuad(c+11,"immAddr", false,-1, 63,0);
        tracep->declBit(c+1,"addrUpdate clk", false,-1);
        tracep->declQuad(c+2,"addrUpdate pcAddr", false,-1, 63,0);
        tracep->declQuad(c+4,"addrUpdate imm", false,-1, 63,0);
        tracep->declBit(c+6,"addrUpdate jmp", false,-1);
        tracep->declQuad(c+7,"addrUpdate outAddr", false,-1, 63,0);
        tracep->declQuad(c+9,"addrUpdate defaultAddr", false,-1, 63,0);
        tracep->declQuad(c+11,"addrUpdate immAddr", false,-1, 63,0);
    }
}

void VaddrUpdate___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VaddrUpdate___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VaddrUpdate___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VaddrUpdate___024root__traceRegister(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VaddrUpdate___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VaddrUpdate___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VaddrUpdate___024root__traceCleanup, vlSelf);
    }
}

void VaddrUpdate___024root__traceFullSub0(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VaddrUpdate___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VaddrUpdate___024root* const __restrict vlSelf = static_cast<VaddrUpdate___024root*>(voidSelf);
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VaddrUpdate___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VaddrUpdate___024root__traceFullSub0(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullQData(oldp+2,(vlSelf->pcAddr),64);
        tracep->fullQData(oldp+4,(vlSelf->imm),64);
        tracep->fullBit(oldp+6,(vlSelf->jmp));
        tracep->fullQData(oldp+7,(vlSelf->outAddr),64);
        tracep->fullQData(oldp+9,(vlSelf->defaultAddr),64);
        tracep->fullQData(oldp+11,(vlSelf->immAddr),64);
    }
}
