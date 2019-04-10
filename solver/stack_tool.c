/*
** EPITECH PROJECT, 2019
** dante
** File description:
** stack_tool
*/

#include "solver.h"

stack_t *stack_new(vector_t pos)
{
    stack_t *new = NULL;

    new = malloc(sizeof(*new));
    new->pos = pos;
    new->next = NULL;
    return (new);
}

void stack_push(stack_t **stack, vector_t pos)
{
    stack_t *new = NULL;

    new = stack_new(pos);
    new->next = *stack;
    *stack = new;
}

vector_t stack_pop(stack_t **stack)
{
    stack_t *tmp = stack ? *stack : NULL;
    vector_t ret;

    FAIL_IF(!*stack, VECT(-1, -1));
    *stack = (*stack)->next;
    ret.x = tmp->pos.x;
    ret.y = tmp->pos.y;
    free(tmp);
    return (ret);
}

void stack_destroy(stack_t *stack)
{
    stack_t *next = stack ? stack->next : NULL;

    while (next) {
        free(stack);
        stack = next;
        next = next->next;
    }
    free(stack);
}