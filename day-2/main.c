#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

int main(int argc, char **argv) {
  assert(argc > 1 && "Provide at least one argument");

  int total_area = 0;
  int total_length = 0;

  char *token = strtok(argv[1], "\n");
  while (token) {
    int a, b, c = 0;
    if (sscanf(token, "%dx%dx%d", &a, &b, &c) != 3) {
      return EFAULT;
    }

    int vec[4] = {a, b, c, a};
    int min_area = INT_MAX;
    int min_circumference = INT_MAX;
    int package_area = 0;

    for (size_t i = 0; i < sizeof(vec) / sizeof(int) - 1; i++) {
      int area = vec[i] * vec[i + 1];
      package_area += area;
      min_area = MIN(min_area, area);

      int circumference = vec[i] + vec[i + 1];
      min_circumference = MIN(min_circumference, circumference);
    }

    total_area += 2 * package_area + min_area;
    int volume = a * b * c;
    total_length += 2 * min_circumference + volume;

    token = strtok(NULL, "\n");
  }

  printf("Part One: %d; Part Two: %d\n", total_area, total_length);

  return EXIT_SUCCESS;
}
