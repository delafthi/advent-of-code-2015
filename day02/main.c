#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input>\n", argv[0]);
    return EXIT_FAILURE;
  }

  uint32_t total_area = 0;
  uint32_t total_length = 0;

  for (char *line = strtok(argv[1], "\n"); line != NULL;
       line = strtok(NULL, "\n")) {
    int16_t a, b, c = 0;
    if (sscanf(line, "%hdx%hdx%hd", &a, &b, &c) != 3) {
      printf("Failed to scan line: %s\n", line);
      exit(EXIT_FAILURE);
    }

    uint16_t vec[4] = {a, b, c, a};
    int32_t min_area = INT_MAX;
    int32_t min_circumference = INT_MAX;
    int32_t package_area = 0;

    for (size_t i = 0; i < sizeof(vec) / sizeof(vec[0]) - 1; i++) {
      int32_t area = vec[i] * vec[i + 1];
      package_area += area;
      min_area = MIN(min_area, area);

      int32_t circumference = vec[i] + vec[i + 1];
      min_circumference = MIN(min_circumference, circumference);
    }

    total_area += 2 * package_area + min_area;
    int32_t volume = a * b * c;
    total_length += 2 * min_circumference + volume;
  }

  printf("Part One: %d; Part Two: %d\n", total_area, total_length);

  return EXIT_SUCCESS;
}
