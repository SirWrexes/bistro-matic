/*
** EPITECH PROJECT, 2019
** Bistro
** File description:
** UT: ndata creation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"

#include "datastruct/treenode_data.h"
#include "infin_ops.h"

Test(tndata_create, regular_usage)
{
    tndata_t data = NULL;

    cr_assert_not(tndata_create(&data));
    cr_assert_not_null(data);
}

Test(tndata_create, opf)
{
    tndata_t data = NULL;
    str_t opstr = "+";

    cr_assert_not(tndata_create_opf(&data, &opstr));
    cr_assert_not_null(data);
    cr_expect_eq(data->type, OPF);
    cr_expect_eq(data->opf, &infin_add);
}

Test(tndata_create, num)
{
    tndata_t data = NULL;
    str_t numstr = "-42";

    cr_assert_not(tndata_create_num(&data, &numstr));
    cr_assert_not_null(data);
    cr_expect_eq(data->type, NUM);
    cr_expect_eq(data->num->sign, NEGATIVE);
    cr_expect_str_eq(data->num->origin, "-42");
    cr_expect_str_eq(data->num->abs, "42");
    cr_expect_eq(data->num->len, 2);
}

Test(broken_malloc, tndat_create, .init = break_malloc)
{
    tndata_t data = NULL;
    str_t opstr = "*";
    str_t numstr = "+23";

    cr_assert(tndata_create(&data));
    cr_expect_null(data);
    cr_assert(tndata_create_opf(&data, &opstr));
    cr_expect_null(data);
    cr_assert(tndata_create_num(&data, &numstr));
    cr_expect_null(data);
}
