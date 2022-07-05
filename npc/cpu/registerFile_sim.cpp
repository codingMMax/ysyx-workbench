#include "verilated.h"
#include "VregisterFile.h"
#include "verilated_vcd_c.h"

VregisterFile * top = NULL;
VerilatedContext *contextp = NULL;
VerilatedVcdC *tfp = NULL;

void sim_init(){
    contextp = new VerilatedContext;
    top = new VregisterFile;
    tfp = new VerilatedVcdC;
    contextp->traceEverOn(true);
    top->trace(tfp,0);
    tfp->open("registerFile.vcd");
}

void step_and_wave_dump(){
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}


void clk_onecycle(){
    top->clk = 1;
    step_and_wave_dump();
    top->clk = 0;
    step_and_wave_dump();
}

void sim_excite(){
    clk_onecycle();
    clk_onecycle();
    // read register
    top->readReg1 = 1;
    clk_onecycle();
    // write register
    top->readReg1 = 0;
    top->writeReg = 1;
    top->regWirteEN = 1;
    top->dataIn = 0x11;
    clk_onecycle();
    top->regWirteEN = 0;
    top->writeReg = 0;
    clk_onecycle();
    // write register and read register at same time
    top->readReg2 = 2;
    top->writeReg = 2;
    top->regWirteEN = 1;
    clk_onecycle();
    clk_onecycle();
}

int main(){
    sim_init();
    sim_excite();
    tfp->close();
    return 0;
}