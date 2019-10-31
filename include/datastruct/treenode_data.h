/*
** EPITECH PROJECT, 2019
** <project_name>
** File description:
** treenode_data.h -- No description
*/

#ifndef TREENODE_DATA_H
#define TREENODE_DATA_H

#include "datastruct/bignum.h"

typedef void (*opf_t)(bignum_t, bignum_t);

typedef struct
{
    union
    {
        bignum_t num; // Number
        opf_t opf;    // Operation function pointer
    };
    enum // This help knowing which union item is in use
    {
        OPF, // OPeration Function
        NUM, // NUMber
    } type;
} * tndata_t;

// Create a treenode data structure
// Returns true in case of error
bool tndat_create(tndata_t *tndata)
__nonnull;

// Destroy a treenode data structure
void tndat_destroy(tndata_t *tndata)
__nonnull;

// Get an operation function pointer depending on the operator
// Returns NULL in case of unknown operator
opf_t pick_opf(char op)
__const;

#endif /* !TREENODE_DATA_H */
