#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>

/**
 * @brief enumerate the extracted token type
 * 
 */
enum {
  // + - * /
  TK_NOTYPE = 256, TK_EQ = '=',
  TK_ADD = '+',TK_SUB = '-',TK_DIV = '/',TK_MUL='*',
  TK_LEFTBRACK = '(',TK_RIGHTBRACK = ')',TK_NUMBER = 'N',
  TK_REG,TK_HEX

  /* TODO: Add more token types */

} ;

/**
 * @brief define the token extract regex rules
 * 
 */
static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {"\\s+", TK_NOTYPE},    // spaces
  {"(\\+)|(\\s\\+*)", TK_ADD},         // plus
  {"==", TK_EQ},        // equal
  {"-",TK_SUB},          // sub
  {"\\*",TK_MUL},          // multiply
  {"/",TK_DIV},          // divide
  {"^(-[0-9]|[0-9])[0-9]*",TK_NUMBER},
  //{"\\d+",TK_NUMBER},
  // {"(?!0x)\\d+",TK_NUMBER},
  {"\\(",TK_LEFTBRACK},
  {"\\)",TK_RIGHTBRACK},
  {"ra|[sgt]p|[ast][0-9]",TK_REG},
  {"\\$0",TK_REG},
  {"0x[\\da-f]+",TK_HEX}

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;
  int braketComplete = 0;
  nr_token = 0;
  while (e[position] != '\0') {

    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
        if(nr_token > 31){
          Log("Total tokens exceed limit, expression is too long");
        }
      // regex match
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        //reset i
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;
        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s, total token matched:%d",
            i, rules[i].regex, position, substr_len, substr_len, substr_start,nr_token+1);
        position += substr_len;

        switch (rules[i].token_type) {
          case TK_ADD:
         // printf("Addition token detected\n");
          tokens[nr_token].type = TK_ADD;
          strcpy(tokens[nr_token].str,"+\0");
          nr_token ++;
          break;


          case TK_SUB:
         // printf("TK_SUB token detected\n");
          tokens[nr_token].type = TK_SUB;
          strcpy(tokens[nr_token].str,"-\0");
          nr_token ++;
          break;

          case TK_DIV:
         // printf("TK_DIV token detected\n");
          tokens[nr_token].type = TK_DIV;
          strcpy(tokens[nr_token].str,"/\0");      
          nr_token ++;
          break;


          case TK_MUL:
         // printf("TK_MUL token detected\n");
          tokens[nr_token].type = TK_MUL;
          strcpy(tokens[nr_token].str,"*\0");
          nr_token ++;
          break;

          case TK_NUMBER:
         // printf("TK_NUMBER token detected\n");
          tokens[nr_token].type = TK_NUMBER;
          if(substr_len < 31){
          strncpy(tokens[nr_token].str,substr_start,substr_len);           
          tokens[nr_token].str[substr_len] = '\0';
          // printf("substr_len:%d,stored digits:%s\n",substr_len,tokens[nr_token].str);
          nr_token ++;
          break;
          }else{
            Log("Input number is too long ");
            return false;
          }
          case TK_REG:
          printf("TK_REG token detected\n");
          tokens[nr_token].type = TK_REG;
          strncpy(tokens[nr_token].str,substr_start,substr_len);
          printf("substr_len:%d,stored digits:%s\n",substr_len,tokens[nr_token].str);
          nr_token ++;
          break;

          case TK_LEFTBRACK:
         // printf("TK_LEFTBRACK token detected\n");
          braketComplete++;
          tokens[nr_token].type = TK_LEFTBRACK;
          strcpy(tokens[nr_token].str,"(\0");          
          nr_token ++;
          break;

          case TK_RIGHTBRACK:
          //printf("TK_RIGHTBRACK token detected\n");
          braketComplete--;
          tokens[nr_token].type = TK_RIGHTBRACK;
          strcpy(tokens[nr_token].str,")\0");    
          nr_token ++;
          break;          
          
          case TK_NOTYPE:
         // printf("TK_NOTYPE token detected\n");
          break;


          default:
          Log("Invalid expression token:%.*s, only support valid register name, demical number and + - * / operation",substr_len, substr_start);
          break;
        }

      
      }

    }
    // if (i == NR_REGEX) {
    //   Log("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
    //   //return false;
    //   }
  }

      if(braketComplete != 0){
          printf("Please enter complete parenthese\n");
          return false;
        }
  return true;
}
/**
 * @brief check the input expression pratheses correct format
 * 
 * @param start starting position
 * @param end  ending position
 * @return true 
 * @return false 
 */
bool checkParenthese(int start, int end){
  int count = 0;
for(int i = start; i <= end; i++){
    if(tokens[i].type == TK_LEFTBRACK){
      count ++;
      printf("Token[%d]:%s\n",i,tokens[i].str);
    }
    if(tokens[i].type == TK_RIGHTBRACK)
    {
    count --;
      printf("Token[%d]:%s\n",i,tokens[i].str);

    }
    // ( )) more right prathese is invalid 
    //number of ( is fixed before the redudant )
    if(count < 0){
      return false;
    }
  }
  // number of right and left prathese must match
  if(count != 0){
    return false;
  }
  return true;
}
/**
 * @brief find the main operator in the given equation 
 * 
 * @param start start position in tokens
 * @param end end posiiton in tokens
 * @return int the index postion of main operator
 */
int findMainOperator(int start,int end){
  // array used to store the index of operator in extracted tokens
  int opIndex[end-start];
  int numOp = 0;
  for(int i = start; i <= end; i++){
    //collect all the valid oprators in the expression
    // store the index in array
    if(tokens[i].type != TK_NUMBER && tokens[i].type != TK_LEFTBRACK && tokens[i].type != TK_RIGHTBRACK && tokens[i].type != TK_REG){
      opIndex[numOp] = i;
      numOp ++;
    }
    // No main operator in pratheses
    if(tokens[i].type == TK_LEFTBRACK){
      break;
    }
  }
  // defualt main operator is the right most one.
  int mainOp = opIndex[numOp-1];
  // extract the lowest priority operator in the extract the operators.

  for(int i = numOp-1 ; i >= 0 ; i --){
    //scan the whole operator from right to left
    if(tokens[opIndex[i]].type == TK_ADD || tokens[opIndex[i]].type == TK_SUB){
        // if + or - is shown update the add/sub position
        mainOp = opIndex[i];
    }
  }

  return mainOp;

}
/**
 * @brief recursively evaluate the whole extracted tokens 
 * 
 * @param start expression starting position
 * @param end expression end posion
 * @return word_t calculated expression result, -1 if expression is invalid
 */
word_t evaluate(int start,int end, bool * succ){
  word_t result;
  printf("Token start:%s type:%d\n",tokens[start].str,tokens[start].type);

  if(start == end){
    printf("Single token detected\n");
    sscanf(tokens[start].str,"%lu",&result);
    return result;
  }
  // check starting and end prathenthese
  if(tokens[start].type == TK_LEFTBRACK){

    if(checkParenthese(start,end)){
    //surrouned by pratheses evaluate the inner expression
    printf("Prathese check: 282 line\n");
    return evaluate(start + 1, end-1,succ);
  } else{
  //prathenthese check faild
    Log("Invalid expression: prathenses incomplete");
      return -1;
   }
  // no prathenthese token must start and end with digits 
  } else if (tokens[start].type == TK_NUMBER){// && tokens[end].type == TK_NUMBER){
      // evaluate the inner operations
     int mainOperatorPos = findMainOperator(start,end);
     printf("Main operator:%s, type: %d\n",tokens[mainOperatorPos].str,tokens[mainOperatorPos].type);
     word_t val1 = evaluate(start,mainOperatorPos-1,succ);
     word_t val2 = evaluate(mainOperatorPos+1,end,succ);

    switch (tokens[mainOperatorPos].type)
    {
    case TK_ADD:
      return val1 + val2;
    case TK_SUB:
      return val1 - val2;
    case TK_MUL:
      // pointer dereference format: *register or *0x...
      return val1 * val2;
    case TK_DIV:
    if(val2 == 0){
      Log("Invalid expression: zero value in division");
      return -1;
    }else{
      return val1 / val2;
    }

    default:
    Log("Invalid expression: must enter valid operator after digits");
      return -1;
    }     
  } else if(tokens[start].type == TK_REG){
      printf("This is register %s\n",tokens[start].str);
      word_t regVal = isa_reg_str2val(tokens[start].str,succ);
      if(regVal < 0){
        return -1;
      }else{
        return regVal;
      }
  }
  else{
    Log("Invalid expression: must start and end with digits or prathenses,\
    Token start:%s type:%d, Token end:%s type:%d \n",tokens[start].str,tokens[start].type,tokens[end].str,tokens[end].type);
    return -1;
  }
}
// shift all the tokens 1unit ahead
// and reset the last token element as empty
void tokenShiftandRemove(int start, int end){
  for(int i = start; i < end-1;i ++){
    memset(tokens[i].str,0,32);
    strcpy(tokens[i].str,tokens[i+1].str);
    tokens[i].type = tokens[i+1].type;
  }
    memset(tokens[end].str,0,32);
    tokens[end].type = 0;

}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  word_t result;
  /** evaluate the  expression**/

  if(nr_token == 1){
    //single expression
    printf("Single token\n");
    if(tokens[0].type == TK_REG){
      result = isa_reg_str2val(tokens[0].str,success);
    }
    else{
      sscanf(tokens[nr_token-1].str,"%lu",&result);    
      }
    return result;
  }
  //
  int start = 0;
  int end = nr_token-1;
  word_t content;
    // replace the pointers with valid numbers
    // remove the * deference operator
  for(int i = 0; i < nr_token; i ++){
    if(tokens[i].type == TK_MUL){
      // dereference the register
      if(tokens[i+1].type == TK_REG){
        content = isa_reg_str2val(tokens[i+1].str,success);
        if(!(*success)){
          return -1;
        }
        Log("register dereference reg:%s, content:%lx \n",tokens[i+1].str,content); 

      //shift the tokens and copy the dereferenced value
        tokenShiftandRemove(i,end);
        tokens[i].type = TK_NUMBER;
        memcpy(tokens[i].str,(char*)&content,sizeof(word_t));
      }
      // dereference the heximal address
      if(tokens[i+1].type == TK_HEX){
        paddr_t addr;
        sscanf(tokens[i+1].str,"%x",&addr);
        content = paddr_read(addr,4);
        Log("address dereference reg:%s, content:%lx \n",tokens[i+1].str,content); 
        //shift the tokens and copy the dereferenced value
        tokenShiftandRemove(i,end);
        tokens[i].type = TK_NUMBER;
        memcpy(tokens[i].str,(char*)&content,sizeof(word_t));
      }

    }
  }

  result = evaluate(start,end,success);
  if(result < 0){
    *success = false;
    return -1;
  }
  return result;
}
