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

const char *str[] = {"42", "-23", "---42", "+1337sauce", NULL};
const char *origin[] = {"42", "-23", "---42", "+1337", NULL};
const char *absstr[] = {"42", "23", "42", "1337", NULL};
const size_t len[] = {2u, 2u, 2u, 4u};
const unsigned short sign[] = {POSITIVE, NEGATIVE, NEGATIVE, POSITIVE};

Test(str_to_bignum, valid_strings)
{
    bignum_t num[] = {
        str_to_bignum((char **) &str[0]),
        str_to_bignum((char **) &str[1]),
        str_to_bignum((char **) &str[2]),
        str_to_bignum((char **) &str[3]),
        NULL
    };

    for (hindex_t i = 0; str[i] != NULL; i += 1) {
        cr_assert_not_null(num[i]);
        cr_expect_str_eq(num[i]->origin, origin[i]);
        cr_expect_str_eq(num[i]->abs, absstr[i]);
        cr_expect_eq(num[i]->sign, sign[i]);
        cr_expect_eq(num[i]->len, len[i]);
    }
}

Test(str_to_bignum, invalid_strings)
{
    str_t nstr[] = {"caca23", "+", "++--+ 4685", "-ta soeur", NULL};

    for (hindex_t i = 0; nstr[i] != NULL; i += 1)
        cr_assert_null(str_to_bignum(&nstr[i]));
}

Test(broken_malloc, str_to_bignum, .init = fix_malloc, .fini = fix_malloc)
{
    str_t nstr[2] = {"+123", "-987"};

    malloc_counter = 1;
    cr_expect_null(str_to_bignum(&nstr[0]));
    cr_expect_null(str_to_bignum(&nstr[1]));
}
