# include "VaddrUpdate.h"
# include "verilated.h"
# include  "verilated_vcd_c.h"

VaddrUpdate *top = NULL;
VerilatedContext *contextp = NULL;
VerilatedVcdC* tfp = NULL;
void sim_init( u_int64_t pc){
    contextp = new VerilatedContext;
    top = new VaddrUpdate;
    tfp = new VerilatedVcdC;
    contextp->traceEverOn(true);
    top->trace(tfp,0);
    tfp->open("addrUpdate.vcd");
    top->pcAddr = pc;
    top-> imm = 0;
    top->jmp = 0;

}

void step_and_wave_dump(){
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void clk_manipulate(){
    top->clk = 0;
    step_and_wave_dump();
    top->clk = 1;
    step_and_wave_dump();
}

void sim_excite(){
    clk_manipulate();
    clk_manipulate();
    clk_manipulate();
    top->imm = 0x80;
    clk_manipulate();
    clk_manipulate();
    clk_manipulate();
    top->jmp = 1;
    clk_manipulate();
    clk_manipulate();
    clk_manipulate();
    tfp->close();

}

int main(){
    sim_init(0x80000000);
    sim_excite();
    return 0;
}