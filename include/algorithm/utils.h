#ifndef SRC_ALGORITHM_UTILS_H
#define SRC_ALGORITHM_UTILS_H

/**
 * @file
 * @brief Small utility algorithms.
 */

/**
 * @brief Exchanges the values behind two pointers.
 *
 * @note Never pass the same address twice. swap_int swaps through XOR, which
 * clears the value when both pointers alias one object.
 *
 * @param[in,out] value1 Pointer whose value is exchanged with value2.
 * @param[in,out] value2 Pointer whose value is exchanged with value1.
 */
#define swap(value1, value2)                                                   \
    _Generic((value1), int *: swap_int)((value1), (value2))

/**
 * @brief Exchanges the values behind two pointers.
 *
 * Uses three XOR operations instead of a temporary, so it needs no extra
 * storage. Applies the aliasing restriction of swap.
 *
 * @param[in,out] value1 Pointer whose value is exchanged with value2.
 * @param[in,out] value2 Pointer whose value is exchanged with value1.
 */
void swap_int(int *value1, int *value2);

#endif // SRC_ALGORITHM_UTILS_H
