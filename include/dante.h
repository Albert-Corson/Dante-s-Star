/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** dante star
*/

#ifndef DANTE_H_
    #define DANTE_H_

#include "my.h"

typedef struct vector_s {
    int x;
    int y;
} vector_t;

// GENERATOR


// SOLVER

#define VECT(x, y) (vector_t){x, y}
#define FAIL_IF(cond, ret) if (cond) return (ret)
#define FAIL_IF_VOID(cond) if (cond) return

#endif /* !DANTE_H_ */