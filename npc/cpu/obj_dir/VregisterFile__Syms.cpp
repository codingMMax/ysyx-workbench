// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VregisterFile__Syms.h"
#include "VregisterFile.h"
#include "VregisterFile___024root.h"

// FUNCTIONS
VregisterFile__Syms::~VregisterFile__Syms()
{
}

VregisterFile__Syms::VregisterFile__Syms(VerilatedContext* contextp, const char* namep,VregisterFile* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp(modelp)
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
}
