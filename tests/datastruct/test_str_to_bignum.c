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
    str_t str[] = {
        "42",
        "-23",
        "---42",
        "+1337sauce",
        NULL
    };
    str_t origin[] = {
        "42",
        "-23",
        "---42",
        "+1337",
        NULL
    };
    str_t abs[] = {
        origin[0],
        origin[1] + 1,
        origin[2] + 3,
        origin[3] + 1,
        NULL,
    };
    size_t len[] = {
        2u,
        2u,
        2u,
        4u,
    };
    unsigned short sign[] = {
        POSITIVE,
        NEGATIVE,
        NEGATIVE,
        POSITIVE,
    };
    bignum_t num[] = {
        str_to_bignum(&str[0]),
        str_to_bignum(&str[1]),
        str_to_bignum(&str[2]),
        str_to_bignum(&str[3]),
        NULL
    };

    for (hindex_t i = 0; str[i] != NULL; i += 1) {
        cr_assert_not_null(num[i]);
        cr_expect_str_eq(num[i]->origin, origin[i]);
        cr_expect_str_eq(num[i]->abs, abs[i]);
        cr_expect_eq(num[i]->sign, sign[i]);
        cr_expect_eq(num[i]->len, len[i]);
    }
}

Test(str_to_bignum, invalid_strings)
{
    str_t str[] = {
        "caca23",
        "+",
        "++--+ 4685",
        "-ta soeur",
        NULL,
    };

    for (hindex_t i = 0; str[i] != NULL; i += 1)
        cr_assert_null(str_to_bignum(&str[i]));
}

Test(broken_malloc, str_to_bignum, .init = fix_malloc, .fini = fix_malloc)
{
    str_t str[2] = {"+123", "-987"};

    malloc_counter = 1;
    cr_expect_null(str_to_bignum(&str[0]));
    cr_expect_null(str_to_bignum(&str[1]));
}
