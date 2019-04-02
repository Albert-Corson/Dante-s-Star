/*
** EPITECH PROJECT, 2019
** dante
** File description:
** stack_tool
*/

#include "generator.h"

stack_t *stack_new(tile_t *tile)
{
    stack_t *new = NULL;

    FAIL_IF(!tile, NULL);
    new = malloc(sizeof(*new));
    new->tile = tile;
    new->next = NULL;
    return (new);
}

void stack_push(stack_t **stack, tile_t *tile)
{
    stack_t *new = NULL;

    FAIL_IF_VOID(!tile);
    new = stack_new(tile);
    new->next = *stack;
    *stack = new;
}

void stack_pop(stack_t **stack)
{
    stack_t *tmp = *stack;

    FAIL_IF_VOID(!*stack);
    *stack = (*stack)->next;
    free(tmp);
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