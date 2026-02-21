#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

#define LIGHT_GRID_WIDTH 1000
#define LIGHT_GRID_HEIGHT 1000

enum Action {
  UNKNOWN,
  ON,
  OFF,
  TOGGLE,
};

struct Point {
  int x;
  int y;
};

struct Square {
  struct Point anchor;
  int width;
  int height;
};

struct Instruction {
  enum Action action;
  struct Square dest;
};

enum Action action_from_str(char *action) {
  if (strcmp(action, "on") == 0) {
    return ON;
  } else if (strcmp(action, "off") == 0) {
    return OFF;
  } else if (strcmp(action, "toggle") == 0) {
    return TOGGLE;
  } else {
    return UNKNOWN;
  }
}

struct Square square_from_two_points(const struct Point *p1,
                                     const struct Point *p2) {
  struct Point anchor = {
      .x = p1->x <= p2->x ? p1->x : p2->x,
      .y = p1->y <= p2->y ? p1->y : p2->y,
  };
  int width = abs(p1->x - p2->x);
  int height = abs(p1->y - p2->y);

  return (struct Square){
      .anchor = anchor,
      .width = width,
      .height = height,
  };
}

int apply_to_pixel_p1(uint8_t *pixel, const enum Action action) {
  switch (action) {
  case ON:
    *pixel = 1;
    break;
  case OFF:
    *pixel = 0;
    break;
  case TOGGLE:
    *pixel = (!*pixel) & 0x1;
    break;
  default:
    return -EINVAL;
  }

  return 0;
}

int apply_to_pixel_p2(uint8_t *pixel, const enum Action action) {
  switch (action) {
  case ON:
    *pixel += 1;
    break;
  case OFF:
    if (*pixel > 0) {
      *pixel -= 1;
    }
    break;
  case TOGGLE:
    *pixel += 2;
    break;
  default:
    return -EINVAL;
  }

  return 0;
}

int apply_to_grid(uint8_t grid[LIGHT_GRID_HEIGHT][LIGHT_GRID_WIDTH],
                  const struct Instruction *instruction,
                  int (*apply_to_pixel)(uint8_t *, const enum Action)) {

  for (size_t y = 0; y <= instruction->dest.height; y++) {
    for (size_t x = 0; x <= instruction->dest.width; x++) {
      int rc = apply_to_pixel(
          &grid[instruction->dest.anchor.y + y][instruction->dest.anchor.x + x],
          instruction->action);
      if (rc < 0) {
        return rc;
      }
    }
  }
  return 0;
}

int sum(const uint8_t *arr, size_t len) {
  int sum = 0;
  for (size_t i = 0; i < len; i++) {
    sum += arr[i];
  }
  return sum;
}

int main(int argc, char **argv) {
  assert(argc > 1 && "Provide at least one argument");

  uint8_t light_grid_p1[LIGHT_GRID_HEIGHT][LIGHT_GRID_WIDTH] = {0};
  uint8_t light_grid_p2[LIGHT_GRID_HEIGHT][LIGHT_GRID_WIDTH] = {0};

  for (char *line = strtok(argv[1], "\n"); line != NULL;
       line = strtok(NULL, "\n")) {
    if (strncmp(line, "turn ", 5) == 0) {
      line += 5;
    }

    char action_str[128] = {0};
    int x1 = INT_MAX;
    int y1 = INT_MAX;
    int x2 = INT_MAX;
    int y2 = INT_MAX;
    if (sscanf(line, "%s %d,%d through %d,%d", action_str, &x1, &y1, &x2,
               &y2) != 5) {

      printf("Failed to scan line: %s\n", line);
      exit(EXIT_FAILURE);
    }

    if (x1 >= LIGHT_GRID_WIDTH && y1 >= LIGHT_GRID_HEIGHT &&
        x2 >= LIGHT_GRID_WIDTH && y2 >= LIGHT_GRID_HEIGHT) {
      printf("Position exceeds grid size: %d, %d >= %d or %d, %d >= %d\n", x1,
             x2, LIGHT_GRID_WIDTH, y1, y2, LIGHT_GRID_HEIGHT);
      exit(EXIT_FAILURE);
    }

    struct Point p1 = {.x = x1, .y = y1};
    struct Point p2 = {.x = x2, .y = y2};
    struct Square destination = square_from_two_points(&p1, &p2);

    struct Instruction instruction = {.action = action_from_str(action_str),
                                      .dest = destination};
    int rc = apply_to_grid(light_grid_p1, &instruction, apply_to_pixel_p1);
    if (rc < 0) {
      printf("Failed to apply instruction (%d)\n", rc);
      exit(EXIT_FAILURE);
    };

    rc = apply_to_grid(light_grid_p2, &instruction, apply_to_pixel_p2);
    if (rc < 0) {
      printf("Failed to apply instruction (%d)\n", rc);
      exit(EXIT_FAILURE);
    };
  }

  int total_lights_on_p1 =
      sum((uint8_t *)light_grid_p1, LIGHT_GRID_WIDTH * LIGHT_GRID_HEIGHT);
  int total_lights_on_p2 =
      sum((uint8_t *)light_grid_p2, LIGHT_GRID_WIDTH * LIGHT_GRID_HEIGHT);

  printf("Part One: %d; Part Two: %d\n", total_lights_on_p1,
         total_lights_on_p2);

  return EXIT_SUCCESS;
}
