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
#include <time.h>

int cmp(const void *a, const void *b) {
    const int **a2 = (const int **)a;
    const int **b2 = (const int **)b;
    return **a2 - **b2;
}

int main(int argc, const char *argv[]) {
    struct Vector list = Vector(sizeof(struct String), 0);
    struct String str = String("Test");
    struct String str2 = String("avec");
    struct String str3 = String("String");

    float startTime = (float)clock()/CLOCKS_PER_SEC * 1000;

    for (int i = 0; i < 100000; i++) {
        list.pushBack(&list, &str, sizeof(struct String));
        list.pushBack(&list, &str2, sizeof(struct String));
        list.pushBack(&list, &str3, sizeof(struct String));
    }

    float endTime = (float)clock()/CLOCKS_PER_SEC * 1000;

    float timeElapsed = endTime - startTime;
    
    printf("Time elapsed: %f in millisecond\n", timeElapsed);
    printVector(&list);

    struct String str4 = String("insert");
    list.insert(&list, &str4, sizeof(struct String), 1);

    printVector(&list);

    list.remove(&list, 1);

    printVector(&list);

    struct Vector list2 = Vector(sizeof(struct String), 3);
    list2.pushBack(&list2, &str, sizeof(struct String));
    list2.pushBack(&list2, &str2, sizeof(struct String));
    list2.pushBack(&list2, &str3, sizeof(struct String));

    struct Vector list3 = list.concat(&list, &list2);

    printVector(&list3);

    list3.reverse(&list3);

    printVector(&list3);

    _Vector(&list);
    _Vector(&list2);
    _Vector(&list3);
    _String(&str);
    _String(&str2);
    _String(&str3);
    _String(&str4);
    printf("Time elapsed: %f\n", timeElapsed);
    return 0;
}