// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VregisterFile__Syms.h"


void VregisterFile___024root__traceChgSub0(VregisterFile___024root* vlSelf, VerilatedVcd* tracep);

void VregisterFile___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VregisterFile___024root* const __restrict vlSelf = static_cast<VregisterFile___024root*>(voidSelf);
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VregisterFile___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VregisterFile___024root__traceChgSub0(VregisterFile___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlSelf->registerFile__DOT__regs[0]),64);
            tracep->chgQData(oldp+2,(vlSelf->registerFile__DOT__regs[1]),64);
            tracep->chgQData(oldp+4,(vlSelf->registerFile__DOT__regs[2]),64);
            tracep->chgQData(oldp+6,(vlSelf->registerFile__DOT__regs[3]),64);
            tracep->chgQData(oldp+8,(vlSelf->registerFile__DOT__regs[4]),64);
            tracep->chgQData(oldp+10,(vlSelf->registerFile__DOT__regs[5]),64);
            tracep->chgQData(oldp+12,(vlSelf->registerFile__DOT__regs[6]),64);
            tracep->chgQData(oldp+14,(vlSelf->registerFile__DOT__regs[7]),64);
            tracep->chgQData(oldp+16,(vlSelf->registerFile__DOT__regs[8]),64);
            tracep->chgQData(oldp+18,(vlSelf->registerFile__DOT__regs[9]),64);
            tracep->chgQData(oldp+20,(vlSelf->registerFile__DOT__regs[10]),64);
            tracep->chgQData(oldp+22,(vlSelf->registerFile__DOT__regs[11]),64);
            tracep->chgQData(oldp+24,(vlSelf->registerFile__DOT__regs[12]),64);
            tracep->chgQData(oldp+26,(vlSelf->registerFile__DOT__regs[13]),64);
            tracep->chgQData(oldp+28,(vlSelf->registerFile__DOT__regs[14]),64);
            tracep->chgQData(oldp+30,(vlSelf->registerFile__DOT__regs[15]),64);
            tracep->chgQData(oldp+32,(vlSelf->registerFile__DOT__regs[16]),64);
            tracep->chgQData(oldp+34,(vlSelf->registerFile__DOT__regs[17]),64);
            tracep->chgQData(oldp+36,(vlSelf->registerFile__DOT__regs[18]),64);
            tracep->chgQData(oldp+38,(vlSelf->registerFile__DOT__regs[19]),64);
            tracep->chgQData(oldp+40,(vlSelf->registerFile__DOT__regs[20]),64);
            tracep->chgQData(oldp+42,(vlSelf->registerFile__DOT__regs[21]),64);
            tracep->chgQData(oldp+44,(vlSelf->registerFile__DOT__regs[22]),64);
            tracep->chgQData(oldp+46,(vlSelf->registerFile__DOT__regs[23]),64);
            tracep->chgQData(oldp+48,(vlSelf->registerFile__DOT__regs[24]),64);
            tracep->chgQData(oldp+50,(vlSelf->registerFile__DOT__regs[25]),64);
            tracep->chgQData(oldp+52,(vlSelf->registerFile__DOT__regs[26]),64);
            tracep->chgQData(oldp+54,(vlSelf->registerFile__DOT__regs[27]),64);
            tracep->chgQData(oldp+56,(vlSelf->registerFile__DOT__regs[28]),64);
            tracep->chgQData(oldp+58,(vlSelf->registerFile__DOT__regs[29]),64);
            tracep->chgQData(oldp+60,(vlSelf->registerFile__DOT__regs[30]),64);
            tracep->chgQData(oldp+62,(vlSelf->registerFile__DOT__regs[31]),64);
        }
        tracep->chgQData(oldp+64,(vlSelf->dataIn),64);
        tracep->chgBit(oldp+66,(vlSelf->regWirteEN));
        tracep->chgBit(oldp+67,(vlSelf->rst));
        tracep->chgBit(oldp+68,(vlSelf->clk));
        tracep->chgQData(oldp+69,(vlSelf->outData1),64);
        tracep->chgQData(oldp+71,(vlSelf->outData2),64);
        tracep->chgCData(oldp+73,(vlSelf->readReg1),5);
        tracep->chgCData(oldp+74,(vlSelf->readReg2),5);
        tracep->chgCData(oldp+75,(vlSelf->writeReg),5);
    }
}

void VregisterFile___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VregisterFile___024root* const __restrict vlSelf = static_cast<VregisterFile___024root*>(voidSelf);
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    }
}
