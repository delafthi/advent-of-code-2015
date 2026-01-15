#ifndef SRC_DAY02_PACKAGE_H
#define SRC_DAY02_PACKAGE_H

/**
 * @brief Rectangular package dimensions.
 */
struct Package {
    int length; ///< Extent along the length axis.
    int width;  ///< Extent along the width axis.
    int height; ///< Extent along the height axis.
};

/**
 * @brief Parse three package dimensions from delimited integers.
 *
 * @param[out] package Receives parsed length, width, and height.
 * @param[in] string Null-terminated input containing three base-10 integers.
 * @param[in] delimiter Null-terminated text separating integers, such as `x`.
 * @return Number of assignments made by `sscanf`, normally from 0 through 3.
 *
 * @note package can be partially updated or left unchanged when return value is
 * less than 3.
 */
int package_from_string(struct Package *package, const char *string,
                        const char *delimiter);

/**
 * @brief Calculate total surface area of a rectangular package.
 *
 * @param[in] package Package whose dimensions are measured.
 * @return Surface area in squared dimension units.
 */
int get_package_surface(const struct Package *package);

/**
 * @brief Calculate volume of a rectangular package.
 *
 * @param[in] package Package whose dimensions are measured.
 * @return Volume in cubic dimension units.
 */
int get_package_volume(const struct Package *package);

/**
 * @brief Copy package dimensions into a nondecreasing array.
 *
 * @param[out] sorted_package_dims Writable array with room for at least three
 * integers.
 * @param[in] package Package supplying dimensions.
 */
void get_sorted_package_dims(int sorted_package_dims[3],

                             const struct Package *package);

#endif // SRC_DAY02_PACKAGE_H
