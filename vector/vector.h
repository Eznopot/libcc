/*
** EPITECH PROJECT, 2022
** LIBCC
** File description:
** vector
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include.h"
#include "../string/string.h"

struct Vector Vector(size_t type);
void _Vector(struct Vector *this);
int pushBackElem(struct Vector *this, void *data, int size);
int popBackElem(struct Vector *this);
int sizeVector(struct Vector *this);
struct Vector concatVector(struct Vector *this, struct Vector *toAdd);
int insertElem(struct Vector *this, void *data, int size, int pos);
int removeElem(struct Vector *this, int pos);
int reverseVector(struct Vector *this);
int sortVector(struct Vector *this, int (cmp)(const void *, const void *));

int test(struct Vector *this);
int printVector(struct Vector *this);

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
    int (*remove)(struct Vector *, int);
    int (*size)(struct Vector *);
    int (*reverse)(struct Vector *);
    int (*sort)(struct Vector *, int (const void *, const void *));

    void **data;
    int * sizeElem;
    int mallocSize;
    size_t type; // sizeof(char *) par exemple
};
#endif /* !VECTOR_H_ */
