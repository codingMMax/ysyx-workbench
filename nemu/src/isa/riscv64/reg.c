#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
/**
 * @brief display all the register info
 * 
 */
void isa_reg_display() {
  for (int i = 0; i < 32; i ++){
    printf("%d: %s 0x%lx  ",i+1,reg_name(i,64),cpu.gpr[i]);
    if(((i + 1) % 8) == 0) printf("\n");    
  }
  printf("cpu pc:0x%lx",cpu.pc);
  printf("\n");
}
/**
 * @brief transfer register string to value
 * 
 * @param s  input string
 * @param success 
 * @return word_t 
 */
word_t isa_reg_str2val(const char *s, bool *success) {
    for (int i = 0; i < 32; i ++){
      if(strcmp(s,reg_name(i,64)) == 0){
        printf("Register find: %s:%lx\n",s,cpu.gpr[i]);
        return cpu.gpr[i];
      }
    }
  printf("Invalid register input\n");
  *success = false;
  return -1;
}
