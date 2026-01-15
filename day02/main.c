#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

int main(int argc, char **argv) {
  assert(argc > 1 && "Provide at least one argument");

  uint32_t total_area = 0;
  uint32_t total_length = 0;

  for (char *line = strtok(argv[1], "\n"); line != NULL;
       line = strtok(NULL, "\n")) {
    int16_t a, b, c = 0;
    if (sscanf(line, "%hdx%hdx%hd", &a, &b, &c) != 3) {
      printf("Failed to scan line: %s\n", line);
      exit(EXIT_FAILURE);
    }

    uint8_t vec[4] = {a, b, c, a};
    int16_t min_area = INT_MAX;
    int16_t min_circumference = INT_MAX;
    int8_t package_area = 0;

    for (size_t i = 0; i < sizeof(vec) / sizeof(int) - 1; i++) {
      int16_t area = vec[i] * vec[i + 1];
      package_area += area;
      min_area = MIN(min_area, area);

      int16_t circumference = vec[i] + vec[i + 1];
      min_circumference = MIN(min_circumference, circumference);
    }

    total_area += 2 * package_area + min_area;
    int32_t volume = a * b * c;
    total_length += 2 * min_circumference + volume;
  }

  printf("Part One: %d; Part Two: %d\n", total_area, total_length);

  return EXIT_SUCCESS;
}
