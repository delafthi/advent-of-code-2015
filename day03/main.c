#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

#include "lib/list.h"

enum Direction {
  LEFT = '<',
  UP = '^',
  RIGHT = '>',
  DOWN = 'v',
};

struct Position {
  int x;
  int y;
};

struct Element {
  struct Position position;
  struct ListNode list_node;
};

int move(struct Position *pos, char instruction) {
  switch (instruction) {
  case LEFT:
    pos->x--;
    break;
  case UP:
    pos->y++;
    break;
  case DOWN:
    pos->y--;
    break;
  case RIGHT:
    pos->x++;
    break;
  default:
    return -EINVAL;
  }

  return 0;
}

bool is_position_in_list(const struct List *list, const struct Position *pos) {
  for (struct ListNode *elem = list->head; elem != NULL; elem = elem->next) {
    struct Element *container_elem =
        container_of(elem, struct Element, list_node);
    if (memcmp(&container_elem->position, pos, sizeof(struct Position)) == 0) {
      return true;
    }
  }
  return false;
}

const struct Position start = {0, 0};

int main(int argc, char **argv) {
  assert(argc > 1 && "Provide at least one argument");

  struct Position santa_p1 = start;
  struct Position santa_p2 = start;
  struct Position robo_santa_p2 = start;
  bool santas_turn_p2 = true;

  struct List history_p1;
  list_init(&history_p1);
  struct List history_p2;
  list_init(&history_p2);

  struct Element *init = malloc(sizeof(struct Element));
  if (init == NULL) {
    exit(EXIT_FAILURE);
  }
  init->position = start;
  list_push_head(&history_p1, &init->list_node);
  list_push_head(&history_p2, &init->list_node);

  char *first_argument = argv[1];
  size_t instruction_iterator = 0;
  for (char instruction = first_argument[instruction_iterator];
       instruction != '\0';
       instruction = first_argument[++instruction_iterator]) {
    struct Position *current_santa_p2 =
        santas_turn_p2 ? &santa_p2 : &robo_santa_p2;
    santas_turn_p2 = !santas_turn_p2;

    (void)move(&santa_p1, instruction);
    (void)move(current_santa_p2, instruction);

    if (!is_position_in_list(&history_p1, &santa_p1)) {
      struct Element *new = malloc(sizeof(struct Element));
      if (new == NULL) {
        printf("Failed to allocate new list element\n");
        exit(EXIT_FAILURE);
      }
      new->position = santa_p1;
      list_push_head(&history_p1, &new->list_node);
    }

    if (!is_position_in_list(&history_p2, current_santa_p2)) {
      struct Element *new = malloc(sizeof(struct Element));
      if (new == NULL) {
        printf("Failed to allocate new list element\n");
        exit(EXIT_FAILURE);
      }
      new->position = *current_santa_p2;
      list_push_head(&history_p2, &new->list_node);
    }
  }

  printf("Part One: %zu; Part Two: %zu\n", history_p1.size, history_p2.size);

  return EXIT_SUCCESS;
}
