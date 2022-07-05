#include "verilated.h"
#include "VALU.h"
#include "verilated_vcd_c.h"

/* declare instances and setting variables*/
VALU* top = NULL;
VerilatedContext *contextp = NULL;
VerilatedVcdC *tfp = NULL;

u_int64_t addInstruction = 0x0000003B;
u_int64_t subInstruction = 0x4000003B;
u_int64_t andInstruction = 0x0000383B;
u_int64_t orInstruction  = 0x0000303B;

/*instruction type need further decode
  the type should be generated from 32-bit instruction 
  itself,rather than manually set
*/

u_int64_t J_type = 0b01;
u_int64_t R_type = 0b10;
u_int64_t I_type = 0b00;


void sim_init(){
    contextp = new VerilatedContext;
    top = new VALU;
    tfp = new VerilatedVcdC;
    contextp->traceEverOn(true);
    top->trace(tfp,0);
    tfp->open("ALU_sim.vcd");
    top->data1 = 0x11;
    top->data2 = 0x2;
    top->imm = 0xff;
}

void step_and_wave_dump(){
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void clk_oneCycle(){
    top->clk = 1;
    step_and_wave_dump();
    top->clk = 0;
    step_and_wave_dump();
}

void setALUControl(u_int64_t instruction,u_int64_t opType){

    top->OPfromMainControl = opType;
    top->instruction = instruction;
    //default immedate = 0xff
    clk_oneCycle();


}

int main(){
    sim_init();
    clk_oneCycle();
    //set add operation r1 + r2
    setALUControl(addInstruction,R_type);
    //set add operaion r1 + imm
    setALUControl(addInstruction,I_type);

    //set sub operation r1 - r2
    setALUControl(subInstruction,R_type);
    // set sub operaion r1 - imm
    setALUControl(subInstruction,I_type);

    //set and operation r1 & r2
    setALUControl(andInstruction,R_type);
    // set and operaion r1 & imm
    setALUControl(andInstruction,I_type);

    //set or operation r1 | r2
    setALUControl(orInstruction,R_type);
    // set or operaion r1 | imm
    setALUControl(orInstruction,I_type);
    // display the expected output
    printf("data1 + data2: %lx, data1 + imm:%lx, \
    data1 - data2: %lx, data1 - imm: %lx, \
    data1 & data2: %lx, data1 & imm:%lx,\
    data1 | data2: %lx, data1 | imm:%lx  \n",\
    top->data1 + top->data2,top->data1 + top->imm,\
    top->data1 - top->data2, top->data1 - top->imm,\
    top->data1 & top->data2, top->data1 & top->imm,\
    top->data1 | top->data2, top->data1 | top->imm);

    tfp->close();
    return 0;
}