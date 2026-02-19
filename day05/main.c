#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

const char *vowels = "aeiou";
const char *forbidden_strings[] = {"ab", "cd", "pq", "xy"};
const int forbidden_strings_count = 4;

bool contains_forbidden_strings(const char *str, const char **forbidden,
                                int forbidden_count) {
  for (size_t i = 0; i < forbidden_count; i++) {
    if (strstr(str, forbidden[i]) != NULL) {
      return true;
    }
  }

  return false;
}

bool contains_n_vowels(const char *str, int n) {
  int num_vowels = 0;

  for (size_t i = 0; i < strlen(str); i++) {
    if (strchr(vowels, str[i]) != NULL) {
      num_vowels++;
      if (num_vowels >= n) {
        return true;
      }
    }
  }

  return false;
}

bool contains_double_char(const char *str) {
  for (size_t i = 0; i < strlen(str) - 1; i++) {
    if (str[i] == str[i + 1]) {
      return true;
    }
  }

  return false;
}

bool contains_pair_without_overlap(const char *str) {
  for (size_t i = 0; i < strlen(str) - 3; i++) {
    const char pair[3] = {str[i], str[i + 1], '\0'};
    if (strstr(str + i + 2, (char *)&pair) != NULL) {
      return true;
    }
  }
  return false;
}

bool contains_char_dontcare_char(const char *str) {
  for (size_t i = 0; i < strlen(str) - 1; i++) {
    if (str[i] == str[i + 2]) {
      return true;
    }
  }

  return false;
}

int main(int argc, char **argv) {
  assert(argc > 1 && "Provide at least one argument");

  int num_nice_strings_p1 = 0;
  int num_nice_strings_p2 = 0;
  for (char *line = strtok(argv[1], "\n"); line != NULL;
       line = strtok(NULL, "\n")) {
    if (!contains_forbidden_strings(line, forbidden_strings,
                                    forbidden_strings_count) &&
        contains_n_vowels(line, 3) && contains_double_char(line)) {
      num_nice_strings_p1++;
    }

    if (contains_pair_without_overlap(line) &&
        contains_char_dontcare_char(line)) {
      num_nice_strings_p2++;
    }
  }

  printf("Part One: %d; Part Two: %d\n", num_nice_strings_p1,
         num_nice_strings_p2);

  return EXIT_SUCCESS;
}
