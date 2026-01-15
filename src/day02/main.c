#include <err.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "package.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        err(EXIT_FAILURE, "Usage: %s input", argv[0]);
    }

    int total_area = 0;
    int total_length = 0;

    for (char *line = strtok(argv[1], "\n"); line != NULL;
         line = strtok(NULL, "\n")) {
        struct Package package = {0};
        int parsed_values = package_from_string(&package, line, "x");
        if (parsed_values != 3) {
            err(EXIT_FAILURE, "Failed to scan line: %s", line);
        }

        // Part 1
        int surface = get_package_surface(&package);
        int sorted_package_dims[3] = {0};
        get_sorted_package_dims(sorted_package_dims, &package);

        int min_area = sorted_package_dims[0] * sorted_package_dims[1];
        total_area += surface + min_area;

        // Part 2
        int volume = get_package_volume(&package);
        int min_circumference =
            2 * (sorted_package_dims[0] + sorted_package_dims[1]);
        total_length += volume + min_circumference;
    }

    (void)printf("Part 1: %d\n", total_area);
    (void)printf("Part 2: %d\n", total_length);

    return EXIT_SUCCESS;
}
