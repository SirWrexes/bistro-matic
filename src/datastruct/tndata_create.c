/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** tndata_create.c -- No description
*/

#include <malloc.h>
#include <stdbool.h>
#include "fox_define.h"
#include "fox_string.h"

#include "datastruct/treenode_data.h"
#include "datastruct/bignum.h"

__nonnull
bool tndata_create_num(tndata_t *tndata, str_t *num)
{
    if (tndata_create(tndata))
        return true;
    (*tndata)->type = NUM;
    (*tndata)->num = str_to_bignum(num);
    return false;
}

__nonnull
bool tndata_create_opf(tndata_t *tndata, str_t *op)
{
    opf_t opf = NULL;
    short prec = 0;

    opf = pick_opf(*(*op)++, &prec);
    if (opf == NULL || tndata_create(tndata))
        return true;
    (*tndata)->type = OPF;
    (*tndata)->opf = opf;
    (*tndata)->prec = prec;
    return false;
}

__nonnull
bool tndata_create(tndata_t *tndata)
{
    *tndata = malloc(sizeof(**tndata));
    if (*tndata == NULL)
        return true;
    return false;
}
