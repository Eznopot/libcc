/*
** EPITECH PROJECT, 2022
** LIBCC
** File description:
** string
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include.h"

struct String String(const char *arr);
struct String *new_String(const char *arr);
void appendString(struct String *this, struct String *string);
int sizeString(struct String *);
int emptyString(struct String *string);
int _String(struct String *string);
char backString(struct String *this);
char frontString(struct String *this);
int compareString(struct String *this, struct String *toCompare);
const char * c_strString(struct String *this);
void clearString(struct String *this);
struct String substrString(struct String *this, int posStart, int posEnd);
struct String replaceString(struct String *this, int posStart, int len, struct String *replaceString);
struct String insertString(struct String *this, int posStart, struct String *insertString);
struct String eraseString(struct String *this, int posStart, int len);
int findString(struct String *this, struct String *toFind);


struct String {
    int (*size)(struct String *);
    int (*empty)(struct String *);
    int (*compare)(struct String *, struct String *);
    void (*append)(struct String *, struct String *);
    char (*back)(struct String *);
    char (*front)(struct String *);
    void (*clear)(struct String *);
    struct String (*substr)(struct String *, int, int);
    struct String (*replace)(struct String *, int, int, struct String *);
    struct String (*insert)(struct String *, int, struct String *);
    struct String (*erase)(struct String *, int, int);
    int (*find)(struct String *, struct String *);

    const char *(*c_str)(struct String *);
    char *data;
};
#endif /* !STRING_H_ */
