/*
** EPITECH PROJECT, 2019
** Bistromatic
** File description:
** Get an operation function pointer depending on the operator
*/

#include "datastruct/treenode_data.h"
#include "infin_ops.h"

__const
opf_t pick_opf(char operator, short *precedence)
{
    switch (operator) {
    default: *precedence = -1; return NULL;
    case '+': *precedence = 0; return &infin_add;
    case '-': *precedence = 0; return &infin_sub;
    case '*': *precedence = 1; return &infin_mul;
    case '/': *precedence = 1; return &infin_div;
    case '%': *precedence = 1; return &infin_mod;
    }
}
