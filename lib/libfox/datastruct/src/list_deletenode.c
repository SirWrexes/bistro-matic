/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Delete a node from the list
*/

#include <malloc.h>

#include "datastruct/fox_list.h"

__a((nonnull(1,2)))
void delete_it(foxnode_t node, void (*destructor)())
{
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    node_destroy(&node, destructor);
}

__a((nonnull(1,2)))
bool list_deletenode(foxlist_t list, void *refptr, void (*destructor)())
{
    for (foxnode_t node = list->head; node != NULL; node = node->next)
        if (node == refptr || node->data == refptr) {
            delete_it(node, destructor);
            list->nodes -= 1;
            return false;
        }
    return true;
}
