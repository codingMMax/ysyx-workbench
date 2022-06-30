#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/paddr.h>
#include <regex.h>
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  uint64_t addr;
  uint64_t value;
  bool free;
  /* TODO: Add more members if necessary */

} WP;

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

/** sdb debugger function definition**/
static int cmd_help(char *args);

/**
 * @brief continue excute current program 
 * 
 * @param args 
 * @return int 
 */
static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}
/**
 * @brief quit the nemu
 * 
 * @param args 
 * @return int 
 */
static int cmd_q(char *args) {
  return -1;
}

/**
 * @brief excute the program in specific instructions
 * 
 * @param args input number of instructions
 * @return 0 if operate successfully, -1 if error
 */
static int cmd_si(char* args){
  int step;
  if(args == NULL) step = 1;
  else{
    sscanf(args,"%d",&step);
    printf("num of instructions: %d\n",step);
    printf("args: %s\n",args);

    if(step > 10){
      printf("Maximum number of instruction to excute is 10, invalid input number.\n");
      return 0;
    }
  }
  cpu_exec(step);
  return 0;
}

/** 
 * inf SUBCMD: 
 * info [r]: print register [r] status
 * info [w]: print watch point [w] information
**/
static int cmd_info(char * args){
    if(args == NULL){
    Log("Please enter complete command");
    return 0 ;
  }
  // input r: requires display the rerigster info
  if(strcmp(args,"r") == 0){
    isa_reg_display();
    return 0;
  }

  //input w: requires display the watch point info
  if(strcmp(args,"w") == 0){
  }

  return 0;
  }
/**
 * @brief scan the target memory area 
 * and output the adjacent N 4 bytes memeory information in heximal format
 * 
 * @param args input register/memory 
 * @return 0 if operate succssfully, -1 if error.
 */
static int cmd_x_scan(char* args){
    if(args == NULL){
    Log("Please enter complete command");
    return 0 ;
  }
  printf("scan memory args:%s\n",args);
  // assume the input is in format %d %lx
  int num;
  paddr_t addr;
  sscanf(args,"%d %x",&num,&addr);
  if(addr < 0x80000000 || addr >  0x87ffffff ){
    printf("Input memory address is out of boundary [ 0x80000000,0x87ffffff]\n");
    return 0;
  }
  // scan the target memroy 
    /* code */
  for (size_t i = 0; i < num; i++)
  {
    printf("current addr:%x, value:0x80%lx\n",addr,paddr_read(addr,4));
    addr += 4;
    if(addr > 0x87ffffff){
      return 0;
    }
  }
  
  return 0;
  };

/**
 * @brief solve the input expression
 * 
 * @param args input expression/register
 * @return 0 if operate succssfully, -1 if error.
 */
static int cmd_p(char* args){
  if(args == NULL){
    Log("Please enter complete command");
    return 0 ;
  }
  bool succ = true;
  word_t result = expr(args,&succ);
  if(!succ){
    Log("Expression evaluation: invalid expression");
    return 0;
  }else{
    printf("Experession result in decimal:%lu\n",result);  
  }
  return 0;
  };


/**
 * @brief set up a watch point at specific memory
 * stop the program when the watched memroy value is changed.
 * 
 * @param args input memory/register 
 * @return 0 if operate successfully, -1 if error.
 */
static int cmd_w(char* args){
    if(args == NULL){
    Log("Please enter complete command");
    return 0 ;
  }

/** regex parameters**/
  enum regType {TK_REG,TK_HEX};
  
  struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {"ra|[sgt]p|[ast][0-9]",TK_REG},
  {"\\$0",TK_REG}
};
  printf("%s\n",args);
  
  return 0;
};
/**
 * @brief delete the watch point.
 * 
 * @param args input watch point location/addr/number.
 * @return 0 if operate successfully, -1 if error.
 */
static int cmd_d(char* args){
  if(args == NULL){
      Log("Please enter complete command");
      return 0 ;
  }

  return 0;};

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display informations about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  {"si","si [N]: Excutes specific N number of instructions, default is 1 instructution",cmd_si },
  {"info","info [SUBCMD] r: print the register status,  w: print watch point information",cmd_info},
  {"x","x [N] [EXPR]: scan memory:solve the [EXPR] value, treat the result as base address then print N 4 bytes memory",cmd_x_scan},
  {"p","p [EXPR] solve the [input ]",cmd_p},
  {"w","w [EXPR] setup a watch-point at [EXPR] location, stop the program when the watched value is changed",cmd_w},
  {"d","d [N] delete watch point [N], N is the number of watch point",cmd_d}
  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)


/**
 * @brief display help info of nemu debugger command
 * 
 * @param args 
 * @return int 
 */
static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}




void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");

    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
      //  printf("cmd matched! cmd =%s, args = %s \n",cmd,args);
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
