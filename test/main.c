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

    struct Vector vector2 = Vector(sizeof(char *));

    vector.pushBack(&vector, &elem, sizeof(elem));
    vector.pushBack(&vector, &elem2, sizeof(elem2));
    //vector.pushBack(&vector, &("AHHHHH"), 8);

    vector2.pushBack(&vector2, &elem3, sizeof(elem3));
    vector2.pushBack(&vector2, &elem4, sizeof(elem4));

    test(&vector);
    test(&vector2);

    printf("\n\n");


    _Vector(&vector);
    _Vector(&vector2);
    return 0;
}