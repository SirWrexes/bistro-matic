/*
** EPITECH PROJECT, 2019
** Bistro-matic
** File description:
** Convert a string to a bignum
*/

#include <malloc.h>
#include "fox_define.h"
#include "fox_string.h"

#include "datastruct/bignum.h"

static __pure
bool number_is_invalid(str_t numstr)
{
    numstr += fox_strspn(numstr, "+-");
    if (!CHAR_IS_NUM(*numstr))
        return true;
    return false;
}

__nonnull
bignum_t str_to_bignum(str_t numstr)
{
    bignum_t num = NULL;
    str_t tmp = NULL;

    if (number_is_invalid(numstr) || bignum_create(&num))
        return NULL;
    num->origin = malloc((num->len + 1) * sizeof(*num->origin));
    if (num->origin == NULL)
        RETURN(NULL, bignum_destroy(&num));
    tmp = num->origin;
    while (*numstr == '-' || *numstr == '+') {
        *tmp++ = *numstr;
        num->sign ^= (bool) (*numstr++ == '-');
    }
    num->abs = tmp;
    while (CHAR_IS_NUM(*numstr)) {
        *tmp++ = *numstr++;
        num->len += 1;
    }
    *tmp = '\0';
    return num;
}
