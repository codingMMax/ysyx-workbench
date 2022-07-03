// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VaddrUpdate.h"
#include "VaddrUpdate__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VaddrUpdate::VaddrUpdate(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VaddrUpdate__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , pcAddr{vlSymsp->TOP.pcAddr}
    , imm{vlSymsp->TOP.imm}
    , jmp{vlSymsp->TOP.jmp}
    , outAddr{vlSymsp->TOP.outAddr}
    , defaultAddr{vlSymsp->TOP.defaultAddr}
    , immAddr{vlSymsp->TOP.immAddr}
    , rootp{&(vlSymsp->TOP)}
{
}

VaddrUpdate::VaddrUpdate(const char* _vcname__)
    : VaddrUpdate(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VaddrUpdate::~VaddrUpdate() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VaddrUpdate___024root___eval_initial(VaddrUpdate___024root* vlSelf);
void VaddrUpdate___024root___eval_settle(VaddrUpdate___024root* vlSelf);
void VaddrUpdate___024root___eval(VaddrUpdate___024root* vlSelf);
QData VaddrUpdate___024root___change_request(VaddrUpdate___024root* vlSelf);
#ifdef VL_DEBUG
void VaddrUpdate___024root___eval_debug_assertions(VaddrUpdate___024root* vlSelf);
#endif  // VL_DEBUG
void VaddrUpdate___024root___final(VaddrUpdate___024root* vlSelf);

static void _eval_initial_loop(VaddrUpdate__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VaddrUpdate___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VaddrUpdate___024root___eval_settle(&(vlSymsp->TOP));
        VaddrUpdate___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VaddrUpdate___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("addrUpdate.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VaddrUpdate___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VaddrUpdate::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VaddrUpdate::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VaddrUpdate___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VaddrUpdate___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VaddrUpdate___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("addrUpdate.v", 3, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VaddrUpdate___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VaddrUpdate::final() {
    VaddrUpdate___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VaddrUpdate::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VaddrUpdate::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VaddrUpdate___024root__traceInitTop(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VaddrUpdate___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaddrUpdate___024root*>(voidSelf);
    VaddrUpdate__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VaddrUpdate___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VaddrUpdate___024root__traceRegister(VaddrUpdate___024root* vlSelf, VerilatedVcd* tracep);

void VaddrUpdate::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VaddrUpdate___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
