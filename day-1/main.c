#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  assert(argc >= 1 && "At least one argument is required");

  int floor = 0;
  int first_time_in_basement = 0;

  char *first_argument = argv[1];
  size_t character_iterator = 0;
  for (char character = first_argument[character_iterator]; character != '\0';
       character = first_argument[++character_iterator]) {
    if (character == '(') {
      floor++;
    } else if (character == ')') {
      floor--;
    } else {
      return EINVAL;
    }

    if (first_time_in_basement == 0 && floor == -1) {
      first_time_in_basement = character_iterator + 1;
    }
  }

  printf("Part One: %d; Part Two: %d", floor, first_time_in_basement);

  return EXIT_SUCCESS;
}
