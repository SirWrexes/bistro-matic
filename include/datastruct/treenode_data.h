/*
** EPITECH PROJECT, 2019
** <project_name>
** File description:
** treenode_data.h -- No description
*/

#ifndef TREENODE_DATA_H
#define TREENODE_DATA_H

#include "fox_define.h"
#include "datastruct/fox_list.h"

#include "datastruct/bignum.h"

typedef void (*opf_t)(bignum_t, bignum_t);

typedef struct
{
    union
    {
        bignum_t num; // Number
        struct
        {
            opf_t opf;  // Operation function pointer
            short prec; // Operation precedence
        };
    };
    enum // This help knowing which union item is in use
    {
        OPF, // OPeration Function
        NUM, // NUMber
    } type;
} * tndata_t;

// Create an unitialized treenode data structure
// Returns true in case of error
bool tndata_create(tndata_t *tndata)
__nonnull;

// Create an operator function node data
// Returns true in case of error
bool tndata_create_opf(tndata_t *tndata, char op)
__nonnull;

// Create a bignum node data
// Returns true in case of error
bool tndata_create_num(tndata_t *tndata, str_t num)
__nonnull;

// Destroy a treenode data structure
void tndata_destroy(tndata_t *tndata)
__nonnull;

// Get an operation function pointer depending on the operator
// Returns NULL in case of unknown operator
opf_t pick_opf(char op, short *precedence)
__nonnull __const;

// Convert an expression to a revese polish notation list
// In case of error, returns the list, even if NULL or incomplete
// (Yeah it kinda sucks I know but there shouldn't be any error)
foxlist_t expr_to_postfix_list(str_t expr)
__nonnull;

#endif /* !TREENODE_DATA_H */
