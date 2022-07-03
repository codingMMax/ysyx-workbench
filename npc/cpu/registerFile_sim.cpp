#include "verilated.h"
#include "VregisterFile.h"
#include "verilated_vcd_c.h"

VregisterFile * top = NULL;
VerilatedContext *contextp = NULL;
VerilatedVcdC *tfp = NULL;

void sim_init(){
    top = new VregisterFile;
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    contextp->traceEverOn(true);
    top->trace(tfp,0);
    tfp->open("registerFile.vcd");
}