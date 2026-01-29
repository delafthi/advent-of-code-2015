#include "list.h"

void list_init(struct List *list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

bool list_is_empty(struct List *list) { return list->size == 0; }

void list_push_head(struct List *list, struct ListNode *new) {
  new->next = list->head;
  new->prev = NULL;

  if (list->head == NULL) {
    list->tail = new;
  } else {
    list->head->prev = new;
  }
  list->head = new;
  list->size++;
}

struct ListNode *list_pop_head(struct List *list) {
  if (list->head == NULL) {
    return NULL;
  }

  struct ListNode *old_head = list->head;
  list->head = old_head->next;
  if (list->head == NULL) {
    list->tail = NULL;
  } else {
    list->head->prev = NULL;
  }
  list->size--;

  old_head->next = NULL;
  old_head->prev = NULL;
  return old_head;
}

void list_push_tail(struct List *list, struct ListNode *new) {
  new->next = NULL;
  new->prev = list->tail;

  if (list->tail == NULL) {
    list->head = new;
  } else {
    list->tail->next = new;
  }
  list->tail = new;
  list->size++;
}

struct ListNode *list_pop_tail(struct List *list) {
  if (list->tail == NULL) {
    return NULL;
  }

  struct ListNode *old_tail = list->tail;
  list->tail = old_tail->prev;
  if (list->tail == NULL) {
    list->head = NULL;
  } else {
    list->tail->next = NULL;
  }
  list->size--;

  old_tail->next = NULL;
  old_tail->prev = NULL;
  return old_tail;
}
