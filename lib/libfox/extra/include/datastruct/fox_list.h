/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Linked lists are useful !
*/

#ifndef FOX_LIST_H
#define FOX_LIST_H

#include <stdbool.h>
#include "fox_define.h"

/* ------------------------------------------------------------------------ */

// Remember: These are dynamically allocated pointers.
// You MUST use the corresponding destructor when you're done with them.
typedef struct foxlist_s *foxlist_t;
typedef struct foxnode_s *foxnode_t;

// ...unles you use this macro that creates a list that autodestroys itself
// after use.
#define autofoxlist_t __cleanup(shredder) foxlist_t
#define paperblade (*listdata_destructor())

// This is just regular sorcery. Skip to the next part.
typedef void (*paperblade_t)(void *);
void shredder(foxlist_t *listptr) __nonnull;
paperblade_t *stackdata_destructor(void) __const;

/* ------------------------------------------------------------------------ */

struct foxlist_s
{
    count_t nodes;  // Node count in the list
    foxnode_t head; // Top of the list
    foxnode_t tail; // Bottom of the list
};

struct foxnode_s
{
    index_t i;      // Position in the list
    void *data;     // Data container
    foxnode_t prev; // Previous node
    foxnode_t next; // Next node
};

/* ------------------------------------------------------------------------ */

// Create a list
// Returns true in case of error
bool list_create(foxlist_t *listptr)
__nonnull;

// Destroy a list and all of its nodes
// Destructor shall be a function pointer to the data destructor
//   used to free data stored in the nodes.
//   Can be NULL
void list_destroy(foxlist_t *listptr, void (*destructor)(void *))
__a((nonnull(1)));

// Add a node to the list conatining data
// Returns true in case of error
bool list_addnode(foxlist_t list, void *data)
__nonnull;

// Remove a node from the list
// data can either be
//   ¤ a pointer to something contained in a node (will delete the first
//     node which has a matching data pointer, starting from list->head)
//   ¤ a pointer to a node from the list
// destructor can be a pointer to a a destructor that frees data
// Returns true when no match is found
bool list_deletenode(foxlist_t list, void *data)
__a((nonnull(1,2)));

// Create a node
// Returns true in case of error
bool node_create(foxnode_t *nodeptr, void *data)
__nonnull;

// Destroy a node
// Destructor shall be a pointer to the blablabla you know it by now
//   Can be NULL
void node_destroy(foxnode_t *nodeptr, void (*destructor)(void *))
__a((nonnull(1)));

#endif /* !FOX_LIST_H */
