#include <stdio.h>
#include <stdlib.h>

enum Direction {
    UP = '(',
    DOWN = ')',
};

int main(int argc, char **argv) {
    if (argc < 2) {
        (void)fprintf(stderr, "Usage: %s input\n", argv[0]);
        exit(EXIT_FAILURE);
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
            (void)fprintf(stderr, "Unknown instruction: %c\n", instr);
            return EXIT_FAILURE;
        }
        }

        if (first_time_in_basement == 0 && floor == -1) {
            first_time_in_basement = instr_it + 1;
        }
    }

    (void)printf("Part one: %d", floor);
    (void)printf("Part two: %d", first_time_in_basement);

    return EXIT_SUCCESS;
}
