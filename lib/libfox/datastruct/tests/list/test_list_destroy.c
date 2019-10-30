/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: List destruction
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "datastruct/fox_list.h"

Test(list_destroy, nonnull_destructor, .disabled = true)
{

}

Test(list_destroy, null_destructor, .disabled = true)
{

}

Test(list_destroy, empty_list)
{
    foxlist_t list = NULL;

    cr_assert_not(list_create(&list));
    list_destroy(&list, NULL);
    cr_expect_null(list);
}

Test(list_destroy, null_list)
{
    foxlist_t list = NULL;

    list_destroy(&list, NULL);
    cr_assert(true);
}

