#include <err.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Direction characters.
 */
enum Direction {
    UP = '(',   /// Move up one floor.
    DOWN = ')', /// Move down one floor.
};

int main(int argc, char **argv) {
    if (argc < 2) {
        err(EXIT_FAILURE, "Usage: %s input", argv[0]);
    };

    int floor = 0;
    int first_time_in_basement = 0;

    char *instr_str = argv[1];
    int instr_it = 0;
    for (char instr = instr_str[instr_it]; instr != '\0';
         instr = instr_str[++instr_it]) {
        switch (instr) {
        case UP: {
            floor++;
            break;
        }
        case DOWN: {
            floor--;
            break;
        }
        default: {
            err(EXIT_FAILURE, "Unknown instruction: %c", instr);
        }
        }

        if (first_time_in_basement == 0 && floor == -1) {
            first_time_in_basement = instr_it + 1;
        }
    }

    (void)printf("Part one: %d\n", floor);
    (void)printf("Part two: %d\n", first_time_in_basement);

    return EXIT_SUCCESS;
}
