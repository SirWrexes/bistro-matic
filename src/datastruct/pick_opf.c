/*
** EPITECH PROJECT, 2019
** Bistromatic
** File description:
** Get an operation function pointer depending on the operator
*/

#include "datastruct/treenode_data.h"
#include "infin_ops.h"

__const
opf_t pick_opf(char operator)
{
    switch (operator) {
        default: return NULL;
        case '+': return &infin_add;
        case '-': return &infin_sub;
        case '*': return &infin_mul;
        case '/': return &infin_div;
        case '%': return &infin_mod;
    }
}
