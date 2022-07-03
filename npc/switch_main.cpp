#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include "Vtop.h"
#include <verilated_vcd_c.h>

#define MAX_TIME 200

int main(int argc,char** argv,char** env)
{
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    Vtop *top = new Vtop;
    Verilated::traceEverOn(true);
    // generate waveform
    VerilatedVcdC *sim_trace = new VerilatedVcdC;
    top->trace(sim_trace,1);
    sim_trace->open("waveform.vcd");

    while (contextp->time() < MAX_TIME && !contextp->gotFinish())
    {
        contextp->timeInc(1);
        int A = rand() & 1;
        int B = rand() & 1;
        top->a = A;
        top->b = B;
        top->eval();
        sim_trace->dump(contextp->time());
        printf("a=%d, b=%d, f=%d\n", A, B, top->f);
        assert(top->f == A ^ B);

    }
    sim_trace->close();
    return 0;
}