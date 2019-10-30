/*
** EPITECH PROJECT, 2019
** Bistro-matic
** File description:
** UT: Bignum creation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"

#include "datastruct/bignum.h"

Test(bignum_create, regular_usage)
{
    bignum_t num = NULL;

    cr_assert_not(bignum_create(&num));
    cr_assert_not_null(num);
    cr_expect_null(num->origin);
    cr_expect_null(num->origin);
    cr_expect_eq(num->len, 0);
    cr_expect_eq(num->sign, POSITIVE);
}

Test(bignum_create, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    bignum_t num = NULL;

    cr_assert(bignum_create(&num));
    cr_expect_null(num);
}
