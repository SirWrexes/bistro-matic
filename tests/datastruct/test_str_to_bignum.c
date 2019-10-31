/*
** EPITECH PROJECT, 2019
** Bistro-matic
** File description:
** UT: bignum creation
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_define.h"

#include "datastruct/bignum.h"

Test(str_to_bignum, valid_strings)
{
    hcount_t ntests = 5;
    str2c_t str[] = {
        "42",
        "   23",
        "---42",
        "   +-+42",
        "+1337sauce",
    };
    str2c_t origin[] = {
        str[0],
        str[1] + 3,
        str[2],
        str[3] + 3,
        str[4],
    };
    str2c_t abs[] = {
        origin[0],
        origin[1],
        origin[2] + 3,
        origin[3] + 3,
        origin[4] + 1,
    };
    size_t len[] = {
        2u,
        2u,
        2u,
        2u,
        4u,
    };
    unsigned short sign[] = {
        POSITIVE,
        POSITIVE,
        NEGATIVE,
        NEGATIVE,
        POSITIVE,
    };
    bignum_t num[] = {
        str_to_bignum(str[0]),
        str_to_bignum(str[1]),
        str_to_bignum(str[2]),
        str_to_bignum(str[3]),
        str_to_bignum(str[4]),
    };

    for (hindex_t i = 0; i != ntests; i += 1) {
        cr_assert_not_null(num[i], "num[%hi]: NULL", i);
        cr_expect_eq(num[i]->origin, origin[i], "num[%hi]: Wrong origin", i);
        cr_expect_eq(num[i]->sign, sign[i], "num[%hi]: Wrong sign", i);
        cr_expect_eq(num[i]->abs, abs[i], "num[%hi]: Wrong abs", i);
        cr_expect_eq(num[i]->len, len[i], "num[%hi]: Wrong len", i);
    }
}

Test(str_to_bignum, invalid_strings)
{
    cr_expect_null(str_to_bignum("caca23"));
    cr_expect_null(str_to_bignum("++--+  456"));
    cr_expect_null(str_to_bignum("    +ta soeur"));
}

Test(str_to_bignum, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    cr_expect_null(str_to_bignum("+123"));
}
