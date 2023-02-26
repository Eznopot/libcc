/*
** EPITECH PROJECT, 2022
** LIBCC
** File description:
** string
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include.h"

struct Vector Vector(size_t type);
void _Vector(struct Vector *this);
int pushBackElem(struct Vector *this, void *data, int size);
int sizeVector(struct Vector *this);

int test(struct Vector *this);

/* This lib is a like vector in c++, you can create list from every type.
** /!\ whe you need to get the data, you get a ptr on the type: int -> int *, char -> char *
** if the type of the vector is already a ptr nothing change: int * -> int *, char * -> char *
*/
struct Vector {
    int (*pushBack)(struct Vector *, void *, int);
    int (*size)(struct Vector *);

    void **data;
    size_t type;
};
#endif /* !VECTOR_H_ */
