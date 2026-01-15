#include "package.h"

#include <errno.h>
#include <stdio.h>

#include "algorithm/sort.h"

enum { FORMAT_STR_SIZE = 32 };

// NOLINTBEGIN[bugprone-easily-swappable-parameters]: I want that signature to
// look like this
int package_from_string(struct Package *package, const char *string,
                        const char *delimiter) {
    char format_str[FORMAT_STR_SIZE] = {0};
    snprintf(format_str, FORMAT_STR_SIZE, "%%d%s%%d%s%%d", delimiter,
             delimiter);
    return sscanf(string, format_str, &package->length, &package->width,
                  &package->height);
}
// NOLINTEND[bugprone-easily-swappable-parameters]

int get_package_surface(const struct Package *package) {
    return 2 * ((package->length * package->width) +
                (package->length * package->height) +
                (package->width * package->height));
}
int get_package_volume(const struct Package *package) {
    return package->length * package->width * package->height;
}

void get_sorted_package_dims(int sorted_package_dims[3],
                             const struct Package *package) {
    sorted_package_dims[0] = package->length;
    sorted_package_dims[1] = package->width;
    sorted_package_dims[2] = package->height;

    bubble_sort(sorted_package_dims, 3);
}
