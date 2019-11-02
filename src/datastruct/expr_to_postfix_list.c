/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** expr_to_postfix_list.c -- No description
*/

#include "fox_datastruct.h"
#include "fox_define.h"
#include "fox_string.h"

#include "datastruct/bignum.h"
#include "datastruct/treenode_data.h"

__nonnull
foxlist_t expr_to_postfix_list(str_t expr)
{
    foxlist_t li = NULL;
    tndata_t data = NULL;
    autofoxstack_t st = NULL;

    if (list_create(&li) || stack_create(&st))
        return NULL;
    while (*expr != '\0') {
        if (tndata_create_num(&data, expr))
            return li;
        list_addnode(li, data);
        expr = data->num->abs + data->num->len;
        expr += fox_strspn(expr, STR_WHITESPACE);
        if (*expr == '\0')
            break;
        if (tndata_create_opf(&data, *expr++))
            return li;
        while (st->items > 0
            && ((tndata_t) st->realtop->data)->prec < data->prec)
            list_addnode(li, stack_pop(st));
        stack_push(st, data);
    }
    while(st->items)
        list_addnode(li, stack_pop(st));
    return li;
}
