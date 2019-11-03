/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** expr_to_postfix_list.c -- No description
*/

#include "fox_define.h"
#include "fox_string.h"
#include "fox_datastruct.h"

#include "datastruct/bignum.h"
#include "datastruct/treenode_data.h"

__const
static bool creation_failed(foxlist_t *liptr, foxstack_t *stptr)
{
    list_destroy(liptr, &tndata_destroy);
    stack_destroy(stptr, NULL);
    return true;
}

__nonnull
static bool process_current_node(str_t *expr, foxlist_t *li, foxstack_t *st)
{
    tndata_t data = NULL;

    if (tndata_create_num(&data, expr) || list_addnode(*li, data))
        return creation_failed(li, st);
    if (*expr == '\0')
        return false;
    if (tndata_create_opf(&data, expr))
        return creation_failed(li, st);
    while (
        (*st)->items && ((tndata_t)(*st)->realtop->data)->prec >= data->prec)
        list_addnode(*li, stack_pop(*st));
    stack_push(*st, data);
    return false;
}

__nonnull
foxlist_t expr_to_postfix_list(str_t expr)
{
    foxlist_t li = NULL;
    foxstack_t st = NULL;

    if (list_create(&li) || stack_create(&st))
        return NULL;
    while (*expr != '\0')
        if (process_current_node(&expr, &li, &st))
            return NULL;
    while (st->items)
        list_addnode(li, stack_pop(st));
    return li;
}
