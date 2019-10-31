/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_pick_opf.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "datastruct/treenode_data.h"
#include "infin_ops.h"

Test(infin_ops, regular_usage)
{
    cr_expect_eq(pick_opf('+'), &infin_add);
    cr_expect_eq(pick_opf('-'), &infin_sub);
    cr_expect_eq(pick_opf('*'), &infin_mul);
    cr_expect_eq(pick_opf('/'), &infin_div);
    cr_expect_eq(pick_opf('%'), &infin_mod);
    cr_expect_null(pick_opf('\0'));
}
