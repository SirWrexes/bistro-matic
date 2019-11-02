/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_tndata_destroy.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "datastruct/treenode_data.h"

Test(tndata_destroy, regular_usage)
{
    tndata_t data = NULL;

    cr_assert_not(tndata_create(&data));
    cr_assert_not_null(data);
    tndata_destroy(&data);
    cr_expect_null(data);
}

Test(tndata_destroy, null_tndata)
{
    tndata_t data = NULL;

    tndata_destroy(&data);
    cr_assert(true);
}
