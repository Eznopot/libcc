/*
** LIBCC
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include.h"
#include "../string/string.h"
#include "../list/list.h"
#include <time.h>

int cmp(const void *a, const void *b) {
    const int **a2 = (const int **)a;
    const int **b2 = (const int **)b;
    return **a2 - **b2;
}

int main(int argc, const char *argv[]) {
struct List list = List(sizeof(struct String));
    struct String str = String("Test");
    struct String str2 = String("avec");
    struct String str3 = String("String");

    float startTime = (float)clock();

    for (int i = 0; i < 100000; i++) {
        list.pushBack(&list, &str, sizeof(struct String));
        list.pushBack(&list, &str2, sizeof(struct String));
        list.pushBack(&list, &str3, sizeof(struct String));
    }

    float endTime = (float)clock();

    float timeElapsed = endTime - startTime;
    
    printf("Time elapsed: %f\n", timeElapsed);
    printList(&list);

    struct String str4 = String("insert");
    list.insert(&list, &str4, sizeof(struct String), 1);

    printList(&list);

    list.remove(&list, 1);

    printList(&list);

    struct List list2 = List(sizeof(struct String));
    list2.pushBack(&list2, &str, sizeof(struct String));
    list2.pushBack(&list2, &str2, sizeof(struct String));
    list2.pushBack(&list2, &str3, sizeof(struct String));

    struct List list3 = list.concat(&list, &list2);

    printList(&list3);

    list3.reverse(&list3);

    printList(&list3);

    _List(&list);
    _List(&list2);
    _List(&list3);
    _String(&str);
    _String(&str2);
    _String(&str3);
    _String(&str4);
    printf("Time elapsed: %f\n", timeElapsed);
    return 0;
}