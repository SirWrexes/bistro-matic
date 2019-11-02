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
    short prec = -5;

    cr_expect_eq(pick_opf('+', &prec), &infin_add);
    cr_expect_eq(prec, 0);
    cr_expect_eq(pick_opf('-', &prec), &infin_sub);
    cr_expect_eq(prec, 0);
    cr_expect_eq(pick_opf('*', &prec), &infin_mul);
    cr_expect_eq(prec, 1);
    cr_expect_eq(pick_opf('/', &prec), &infin_div);
    cr_expect_eq(prec, 1);
    cr_expect_eq(pick_opf('%', &prec), &infin_mod);
    cr_expect_eq(prec, 1);
    cr_expect_null(pick_opf('\0', &prec));
    cr_expect_eq(prec, -1);
}
