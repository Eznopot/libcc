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
int popBackElem(struct Vector *this);
int sizeVector(struct Vector *this);
struct Vector concatVector(struct Vector *this, struct Vector *toAdd);
int insertElem(struct Vector *this, void *data, int size, int pos);

int test(struct Vector *this);

/* This lib is a like vector in c++, you can create list from every type.
** /!\ whe you need to get the data, you get a ptr on the type: int -> int *, char -> char *
** if the type of the vector is already a ptr nothing change: int * -> int *, char * -> char *
** So you need to cast it if you want to retrieve the data
*/
struct Vector {
    int (*pushBack)(struct Vector *, void *, int);
    int (*popBack)(struct Vector *);
    struct Vector (*concat)(struct Vector *, struct Vector *);
    int (*insert)(struct Vector *, void *, int, int);
    int (*size)(struct Vector *);

    void **data;
    size_t type;
};
#endif /* !VECTOR_H_ */
