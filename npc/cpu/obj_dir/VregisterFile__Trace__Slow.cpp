// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VregisterFile__Syms.h"


void VregisterFile___024root__traceInitSub0(VregisterFile___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VregisterFile___024root__traceInitTop(VregisterFile___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VregisterFile___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VregisterFile___024root__traceInitSub0(VregisterFile___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declQuad(c+65,"dataIn", false,-1, 63,0);
        tracep->declBit(c+67,"regWirteEN", false,-1);
        tracep->declBit(c+68,"rst", false,-1);
        tracep->declBit(c+69,"clk", false,-1);
        tracep->declQuad(c+70,"outData1", false,-1, 63,0);
        tracep->declQuad(c+72,"outData2", false,-1, 63,0);
        tracep->declBus(c+74,"readReg1", false,-1, 4,0);
        tracep->declBus(c+75,"readReg2", false,-1, 4,0);
        tracep->declBus(c+76,"writeReg", false,-1, 4,0);
        tracep->declQuad(c+65,"registerFile dataIn", false,-1, 63,0);
        tracep->declBit(c+67,"registerFile regWirteEN", false,-1);
        tracep->declBit(c+68,"registerFile rst", false,-1);
        tracep->declBit(c+69,"registerFile clk", false,-1);
        tracep->declQuad(c+70,"registerFile outData1", false,-1, 63,0);
        tracep->declQuad(c+72,"registerFile outData2", false,-1, 63,0);
        tracep->declBus(c+74,"registerFile readReg1", false,-1, 4,0);
        tracep->declBus(c+75,"registerFile readReg2", false,-1, 4,0);
        tracep->declBus(c+76,"registerFile writeReg", false,-1, 4,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+1+i*2,"registerFile regs", true,(i+0), 63,0);}}
    }
}

void VregisterFile___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VregisterFile___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VregisterFile___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VregisterFile___024root__traceRegister(VregisterFile___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VregisterFile___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VregisterFile___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VregisterFile___024root__traceCleanup, vlSelf);
    }
}

void VregisterFile___024root__traceFullSub0(VregisterFile___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VregisterFile___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VregisterFile___024root* const __restrict vlSelf = static_cast<VregisterFile___024root*>(voidSelf);
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VregisterFile___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VregisterFile___024root__traceFullSub0(VregisterFile___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlSelf->registerFile__DOT__regs[0]),64);
        tracep->fullQData(oldp+3,(vlSelf->registerFile__DOT__regs[1]),64);
        tracep->fullQData(oldp+5,(vlSelf->registerFile__DOT__regs[2]),64);
        tracep->fullQData(oldp+7,(vlSelf->registerFile__DOT__regs[3]),64);
        tracep->fullQData(oldp+9,(vlSelf->registerFile__DOT__regs[4]),64);
        tracep->fullQData(oldp+11,(vlSelf->registerFile__DOT__regs[5]),64);
        tracep->fullQData(oldp+13,(vlSelf->registerFile__DOT__regs[6]),64);
        tracep->fullQData(oldp+15,(vlSelf->registerFile__DOT__regs[7]),64);
        tracep->fullQData(oldp+17,(vlSelf->registerFile__DOT__regs[8]),64);
        tracep->fullQData(oldp+19,(vlSelf->registerFile__DOT__regs[9]),64);
        tracep->fullQData(oldp+21,(vlSelf->registerFile__DOT__regs[10]),64);
        tracep->fullQData(oldp+23,(vlSelf->registerFile__DOT__regs[11]),64);
        tracep->fullQData(oldp+25,(vlSelf->registerFile__DOT__regs[12]),64);
        tracep->fullQData(oldp+27,(vlSelf->registerFile__DOT__regs[13]),64);
        tracep->fullQData(oldp+29,(vlSelf->registerFile__DOT__regs[14]),64);
        tracep->fullQData(oldp+31,(vlSelf->registerFile__DOT__regs[15]),64);
        tracep->fullQData(oldp+33,(vlSelf->registerFile__DOT__regs[16]),64);
        tracep->fullQData(oldp+35,(vlSelf->registerFile__DOT__regs[17]),64);
        tracep->fullQData(oldp+37,(vlSelf->registerFile__DOT__regs[18]),64);
        tracep->fullQData(oldp+39,(vlSelf->registerFile__DOT__regs[19]),64);
        tracep->fullQData(oldp+41,(vlSelf->registerFile__DOT__regs[20]),64);
        tracep->fullQData(oldp+43,(vlSelf->registerFile__DOT__regs[21]),64);
        tracep->fullQData(oldp+45,(vlSelf->registerFile__DOT__regs[22]),64);
        tracep->fullQData(oldp+47,(vlSelf->registerFile__DOT__regs[23]),64);
        tracep->fullQData(oldp+49,(vlSelf->registerFile__DOT__regs[24]),64);
        tracep->fullQData(oldp+51,(vlSelf->registerFile__DOT__regs[25]),64);
        tracep->fullQData(oldp+53,(vlSelf->registerFile__DOT__regs[26]),64);
        tracep->fullQData(oldp+55,(vlSelf->registerFile__DOT__regs[27]),64);
        tracep->fullQData(oldp+57,(vlSelf->registerFile__DOT__regs[28]),64);
        tracep->fullQData(oldp+59,(vlSelf->registerFile__DOT__regs[29]),64);
        tracep->fullQData(oldp+61,(vlSelf->registerFile__DOT__regs[30]),64);
        tracep->fullQData(oldp+63,(vlSelf->registerFile__DOT__regs[31]),64);
        tracep->fullQData(oldp+65,(vlSelf->dataIn),64);
        tracep->fullBit(oldp+67,(vlSelf->regWirteEN));
        tracep->fullBit(oldp+68,(vlSelf->rst));
        tracep->fullBit(oldp+69,(vlSelf->clk));
        tracep->fullQData(oldp+70,(vlSelf->outData1),64);
        tracep->fullQData(oldp+72,(vlSelf->outData2),64);
        tracep->fullCData(oldp+74,(vlSelf->readReg1),5);
        tracep->fullCData(oldp+75,(vlSelf->readReg2),5);
        tracep->fullCData(oldp+76,(vlSelf->writeReg),5);
    }
}
