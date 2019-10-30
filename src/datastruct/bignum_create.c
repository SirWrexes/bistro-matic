/*
** EPITECH PROJECT, 2019
** Bistro-matic
** File description:
** Create and initialize a bignum structure
*/

#include <malloc.h>
#include <stdbool.h>

#include "datastruct/bignum.h"

__nonnull
bool bignum_create(bignum_t *num)
{
    *num = malloc(sizeof(**num));
    if (*num == NULL)
        return true;
    (*num)->origin = NULL;
    (*num)->abs = NULL;
    (*num)->len = 0;
    (*num)->sign = POSITIVE;
    return false;
}
