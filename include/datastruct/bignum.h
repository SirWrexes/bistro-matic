/*
** EPITECH PROJECT, 2019
** Bistro-matic
** File description:
** Structure to store big numbers
*/

#ifndef BIGNUM_H
#define BIGNUM_H

#include <stddef.h>
#include <stdbool.h>
#include "fox_define.h"

typedef struct bignum_s
{
    str2c_t origin; // Origin string including sign(s)
    str2c_t abs;    // Only the digits
    size_t len;     // Number of digits in abs
    enum
    {
        POSITIVE = 0,
        NEGATIVE = 1,
    } sign;
} * bignum_t;

// Create a new bignum structure
// Returns true in case of error
bool bignum_create(bignum_t *num)
__nonnull;

// Destroy a bignum structur
void bignum_destroy(bignum_t *num)
__nonnull;

// Convert a string into a bignum
// Returns NULL in case of error
bignum_t str_to_bignum(str2c_t str)
__nonnull;

#endif /* !BIGNUM_H */
