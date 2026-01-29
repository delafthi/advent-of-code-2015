#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

struct List {
  struct ListNode *head;
  struct ListNode *tail;
  size_t size;
};

struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
};

#ifndef container_of
#define container_of(ptr, type, member)                                        \
  ((type *)((char *)(ptr) - offsetof(type, member)))
#endif

void list_init(struct List *list);

bool list_is_empty(struct List *list);

void list_push_head(struct List *list, struct ListNode *new);

struct ListNode *list_pop_head(struct List *list);

void list_push_tail(struct List *list, struct ListNode *new);

struct ListNode *list_pop_tail(struct List *list);

#endif // LIST_H
