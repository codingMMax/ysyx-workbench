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

static int numWP = 0;
static WP wp_pool[NR_WP] = {};
static WP *head = NULL;
static WP *free_head = NULL;
/**
 * @brief initial the watchpoint pool
 * 
 */
void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    // assign index and next ptr
    wp_pool[i].NO = -1; // default number for all the free wp is 0
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].free = true;
  }

  head = NULL;
  free_head = wp_pool;
}

/**
 * @brief insert the curr WP* into specified linked list
 * 
 * @param curr current input wp*
 * @param free 1: insert to free linkedlist, 0: insert to allocaed linkedlist 
 */
void insertToHead(WP* curr, bool free){
  assert(curr != NULL);
  if(free){
  //insert the curr element to free linkedlist
    curr->free = true;
    curr->next = free_head;
    free_head = curr;
  }else{
  //insert the curr element to allocated linkedlist
    curr->free = false;
    curr->next = head;
    head = curr;
  }
}

/**
 * @brief find a valid free element
 * 
 * @return WP*  processed free element
 */
WP* new_wp() {
  if(free_head == NULL){
    assert(numWP == 32);
    Log("NO free Watch Point avaliable");
    return NULL;
  }
// choose the free_head as new_wp
  WP* currFree = free_head;
// move free_head to next element
  free_head = free_head->next;
  insertToHead(currFree,false);
  currFree->NO = numWP;
  numWP ++;

  return currFree;
}
/**
 * @brief free the input wp*
 * 
 * @param wp input wp*
 */
void free_wp(WP* wp){
  assert(wp->free == false);
  // if free the head
  if(wp == head){
    //move head to next element
    head = head->next;
    insertToHead(wp,true);
  }
  else{
    WP* prev = head;
    while (prev->next != wp)
    {
    // get previous element
      prev = prev->next;
    }
    // re-arrange the pointer
    prev->next = wp->next;
    insertToHead(wp,true);
  }
  numWP --;
  wp->NO = -1;
}