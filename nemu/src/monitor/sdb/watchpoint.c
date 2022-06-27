#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  uint64_t addr;
  uint64_t value;
  bool free;
  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].free = true;
  }

  head = NULL;
  free_ = wp_pool;
}
/**
 * @brief return a wp pointer from free wp_pool
 * 
 * @return WP* new free wp pointer
 */
WP* new_wp(){
  // get the a free WP from pool.
  WP curr_free;
  int i;
  for(i = 0; i < NR_WP; i++){
    if(wp_pool[i].free)
    break;
  }
  //modify the found wp element parameters
  curr_free = wp_pool[i];
  curr_free.free = false;
  curr_free.next = NULL;    
  
// move free_ pointer to next wp in the pool
  if(i == NR_WP-1){
    free_ = NULL;
  }else{
    free_ = &wp_pool[i+1];
  }

// add the new wp into head list
  if(head == NULL){
    // empty head list
    head = &curr_free;
    return head;
  }
  else{
    // not empty head list
  WP* curr = head;
  while(curr->next != NULL){
    curr = curr->next;
  }
  curr->next = &curr_free;
  return &curr_free;
  }
  
  
}
/**
 * @brief return the wp to free wp_pool
 * 
 */
void free_wp(WP* wp){
  wp->free = false;
  // free the head node
  if(head == wp){
    wp->next = free_;
    free_ = wp;
    head = NULL;
    return;
  }else{
    WP* curr = head;
    WP* prev = head;
    while(curr != wp){
      prev = curr;
      curr = prev->next;
    }
    // insert to free_ head
    prev->next = curr->next;
    curr->next = free_;
    free_ = curr;
    return;

  }
}
