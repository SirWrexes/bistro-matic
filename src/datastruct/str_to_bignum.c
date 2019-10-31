/*
** EPITECH PROJECT, 2019
** Bistro-matic
** File description:
** Convert a string to a bignum
*/

#include "fox_define.h"
#include "fox_string.h"

#include "datastruct/bignum.h"

static __pure
bool get_sign(str2c_t origin, str2c_t *abs)
{
    bool sign = 0;

    while (*origin == '+' || *origin == '-')
        sign ^= (bool) (*origin++ == '-');
    *abs = origin;
    return sign;
}

static __pure
size_t get_numsize(str2c_t abs)
{
    size_t i = 0;

    while (CHAR_IS_NUM(abs[i]))
        i += 1;
    return i;
}

bignum_t str_to_bignum(str2c_t numstr)
{
    bignum_t num = NULL;
    str2c_t abs = NULL;
    str2c_t origin = numstr + fox_strspn(numstr, STR_WHITESPACE);
    unsigned char sign = get_sign(origin, &abs);
    size_t size = get_numsize(abs);

    if (!fox_isinstr(*origin, "+-" STR_NUMERIC)
        || !fox_isinstr(*abs, STR_NUMERIC))
        return NULL;
    if (bignum_create(&num))
        return NULL;
    num->origin = origin;
    num->abs = abs;
    num->len = size;
    num->sign = sign % 2;
    return num;
}
