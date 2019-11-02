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

static void set_abs(str_t *numstr, str_t *tmp, bignum_t num)
{
    while (CHAR_IS_NUM(**numstr)) {
        *(*tmp)++ = *(*numstr)++;
        num->len += 1;
    }
}

static void set_sign(str_t *numstr, str_t *tmp, bignum_t num)
{
    while (**numstr == '-' || **numstr == '+') {
        *(*tmp)++ = **numstr;
        num->sign ^= (bool) (*(*numstr)++ == '-');
    }
}

static bool number_is_invalid(str_t *numstr)
{
    *numstr += fox_strspn(*numstr, STR_WHITESPACE);
    if (!CHAR_IS_NUM(*(*numstr + fox_strspn(*numstr, "+-"))))
        return true;
    return false;
}

__nonnull
bignum_t str_to_bignum(str_t *numstr)
{
    bignum_t num = NULL;
    str_t tmp = NULL;

    if (number_is_invalid(numstr) || bignum_create(&num))
        return NULL;
    num->origin = malloc((num->len + 1) * sizeof(*num->origin));
    if (num->origin == NULL)
        RETURN(NULL, bignum_destroy(&num));
    tmp = num->origin;
    set_sign(numstr, &tmp, num);
    num->abs = tmp;
    set_abs(numstr, &tmp, num);
    *tmp = '\0';
    *numstr += fox_strspn(*numstr, STR_WHITESPACE);
    return num;
}
