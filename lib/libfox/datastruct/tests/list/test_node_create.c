/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Node creation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"

#include "datastruct/fox_list.h"

Test(node_create, regular_usage)
{
    foxnode_t node = NULL;

    cr_assert_not(foxnode_create(&node, &node));

}
