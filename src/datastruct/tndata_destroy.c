/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** tndata_destroy.c -- No description
*/

#include <malloc.h>

#include "datastruct/treenode_data.h"

__nonnull
void tndata_destroy(tndata_t *data)
{
    free(*data);
    *data = NULL;
}
