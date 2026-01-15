#ifndef SRC_SORT_UTILS_H
#define SRC_SORT_UTILS_H

/**
 * @brief Exchange two integer values in place.
 *
 * @param[in,out] value1 First value to exchange.
 * @param[in,out] value2 Second value to exchange.
 */
#define swap(value1, value2)                                                   \
    (value1) ^= (value2);                                                      \
    (value2) ^= (value1);                                                      \
    (value1) ^= (value2)

#endif // SRC_SORT_UTILS_H
