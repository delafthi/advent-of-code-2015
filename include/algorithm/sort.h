#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

#include <stddef.h>

/**
 * @brief Sorts an `int` array in nondecreasing order.
 *
 * @param[in,out] values Array of count integers to sort.
 * @param[in] count Number of integers in values.
 */
#define bubble_sort(values, count)                                             \
    _Generic((values), int *: bubble_sort_int)((values), (count))

/**
 * @brief Sorts integers in nondecreasing order.
 *
 * @param[in,out] values Array of count integers to sort.
 * @param[in] count Number of integers in values.
 */
void bubble_sort_int(int *values, size_t count);

#endif // ALGORITHM_SORT_H
