/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** postfix_list_to_tree.c -- No description
*/

#include "fox_define.h"
#include "fox_datastruct.h"

#include "datastruct/treenode_data.h"

__nonnull
bool process_current_node(foxnode_t n, foxstack_t stack, foxtree_t tree)
{
    foxtnode_t tnode = NULL;

    if (tnode_create(&tnode, n->data, tree))
        return true;
    switch (((tndata_t) n->data)->type) {
    default: return true;
    case OPF:
        tnode->lnext = stack_pop(stack);
        tnode->rnext = stack_pop(stack);
        __fallthrough;
    case NUM:
        stack_push(stack, tnode);
        return false;
    }
}

__nonnull
foxtree_t postfix_list_to_tree(foxlist_t list)
{
    foxtree_t tree = NULL;
    foxstack_t stack = NULL;

    if (tree_create(&tree) || stack_create(&stack))
        RETURN(NULL, tree_destroy(&tree, NULL), stack_destroy(&stack, NULL));
    for (foxnode_t n = list->head; n != NULL; n = n->next)
        process_current_node(n, stack, tree);
    tree->trunk = stack_pop(stack);
    return tree;
}
