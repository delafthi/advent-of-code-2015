#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

#include <stddef.h>

/**
 * @file
 * @brief In-place sorting algorithms.
 *
 * Each algorithm reorders a caller-owned array of count elements, taking the
 * count explicitly instead of relying on a terminator. bubble_sort is the
 * dispatch entry point; bubble_sort_int implements it for `int` arrays.
 */

/**
 * @brief Sorts an `int` array in nondecreasing order.
 *
 * Dispatches on the array pointer type, so `int *` needs no cast at the call
 * site. Sorts in O(count^2) time and O(1) extra space. A count of 0 or 1 is a
 * no-op.
 *
 * @param[in,out] values Array of count integers to sort.
 * @param[in] count Number of integers in values.
 */
#define bubble_sort(values, count)                                             \
    _Generic((values), int *: bubble_sort_int)((values), (count))

/**
 * @brief Sorts integers in nondecreasing order.
 *
 * Makes exactly count * (count - 1) / 2 comparisons with no early exit, so
 * already sorted input costs the same as unsorted input.
 *
 * @param[in,out] values Array of count integers to sort.
 * @param[in] count Number of integers in values.
 */
void bubble_sort_int(int *values, size_t count);

#endif // ALGORITHM_SORT_H
