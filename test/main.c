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
    char elem[] = "remertyuihugyftrertytrezertyy";
    char elem2[] = "fesfesfes";
    //int elem = 1234567;
    struct Vector vector = Vector(sizeof(char *));

    vector.pushBack(&vector, &elem, sizeof(elem));
    vector.pushBack(&vector, &elem2, sizeof(elem2));
    //printf("%s\n", vector.data);
    printf("%s\n", (char *)(vector.data[0]));
    printf("%s\n", (char *)(vector.data[1]));

    test(&vector);

    _Vector(&vector);
    return 0;
}