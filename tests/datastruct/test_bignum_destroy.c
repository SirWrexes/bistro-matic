/*
** EPITECH PROJECT, 2019
** Bistro-matic
** File description:
** UT: Bignum destruction
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "datastruct/bignum.h"

Test(bignum_destroy, regular_usage)
{
    bignum_t num = NULL;

    cr_assert_not(bignum_create(&num));
    cr_assert_not_null(num);
    bignum_destroy(&num);
    cr_expect_null(num);
}

Test(bignum_destroy, null_handling)
{
    bignum_t num = NULL;

    bignum_destroy(&num);
    cr_assert(true);
}
