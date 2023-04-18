/*
** LIBCC
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include.h"
#include "../string/string.h"
#include "../vector/vector.h"

int main(int argc, const char *argv[]) {
    char elem[] = "testing 1";
    char elem2[] = "testing 2";
    char elem3[] = "testing 3";
    char elem4[] = "testing 4";

    char elem5[] = "-----";

    struct Vector vector = Vector(sizeof(char *));

    vector.pushBack(&vector, &elem, sizeof(elem));
    //vector.pushBack(&vector, &elem2, sizeof(elem2));

    test(&vector);


    _Vector(&vector);
    return 0;
}