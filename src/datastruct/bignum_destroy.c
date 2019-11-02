/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Destroy a bignum
*/

#include <malloc.h>

#include "datastruct/bignum.h"

__nonnull
void bignum_destroy(bignum_t *num)
{
    if (*num == NULL)
        return;
    if ((*num)->origin != NULL)
        free((*num)->origin);
    free(*num);
    *num = NULL;
}
