/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Stack with auto destruction macro type
*/

#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "datastruct/fox_stack.h"

Test(autostack, regular_usage, .signal = SIGABRT)
{
    autofoxtstack_t stack = NULL;

    stack_create(&stack);
    free(stack);
}
