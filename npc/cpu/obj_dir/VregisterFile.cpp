// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VregisterFile.h"
#include "VregisterFile__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VregisterFile::VregisterFile(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VregisterFile__Syms(_vcontextp__, _vcname__, this)}
    , dataIn{vlSymsp->TOP.dataIn}
    , regWirteEN{vlSymsp->TOP.regWirteEN}
    , rst{vlSymsp->TOP.rst}
    , clk{vlSymsp->TOP.clk}
    , outData1{vlSymsp->TOP.outData1}
    , outData2{vlSymsp->TOP.outData2}
    , readReg1{vlSymsp->TOP.readReg1}
    , readReg2{vlSymsp->TOP.readReg2}
    , writeReg{vlSymsp->TOP.writeReg}
    , rootp{&(vlSymsp->TOP)}
{
}

VregisterFile::VregisterFile(const char* _vcname__)
    : VregisterFile(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VregisterFile::~VregisterFile() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VregisterFile___024root___eval_initial(VregisterFile___024root* vlSelf);
void VregisterFile___024root___eval_settle(VregisterFile___024root* vlSelf);
void VregisterFile___024root___eval(VregisterFile___024root* vlSelf);
QData VregisterFile___024root___change_request(VregisterFile___024root* vlSelf);
#ifdef VL_DEBUG
void VregisterFile___024root___eval_debug_assertions(VregisterFile___024root* vlSelf);
#endif  // VL_DEBUG
void VregisterFile___024root___final(VregisterFile___024root* vlSelf);

static void _eval_initial_loop(VregisterFile__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VregisterFile___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VregisterFile___024root___eval_settle(&(vlSymsp->TOP));
        VregisterFile___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VregisterFile___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("registerFile.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VregisterFile___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VregisterFile::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VregisterFile::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VregisterFile___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VregisterFile___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VregisterFile___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("registerFile.v", 3, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VregisterFile___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VregisterFile::final() {
    VregisterFile___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VregisterFile::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VregisterFile::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VregisterFile___024root__traceInitTop(VregisterFile___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VregisterFile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VregisterFile___024root*>(voidSelf);
    VregisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VregisterFile___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VregisterFile___024root__traceRegister(VregisterFile___024root* vlSelf, VerilatedVcd* tracep);

void VregisterFile::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VregisterFile___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
