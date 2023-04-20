/*
** EPITECH PROJECT, 2022
** LIBCC
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include.h"

struct List List(size_t type);
void _List(struct List *this);
int pushBackNode(struct List *this, void *data, int size);
int popBackNode(struct List *this);
int sizeList(struct List *this);
struct List concatList(struct List *this, struct List *toAdd);
int insertNode(struct List *this, void *data, int size, int pos);
int removeNode(struct List *this, int pos);
int reverseList(struct List *this);
int printList(struct List *this);

struct Node {
    void *data;
    int size;
    struct Node *next;
    struct Node *prev;
};

struct List {
    int (*pushBack)(struct List *, void *, int);
    int (*popBack)(struct List *);
    struct List (*concat)(struct List *, struct List *);
    int (*insert)(struct List *, void *, int, int);
    int (*remove)(struct List *, int);
    int (*reverse)(struct List *);
    int (*size)(struct List *);

    struct Node *head;
    struct Node *tail;
};

#endif /* LIST_H_ */