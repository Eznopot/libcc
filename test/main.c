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
#include "../list/list.h"

int cmp(const void *a, const void *b) {
    const int **a2 = (const int **)a;
    const int **b2 = (const int **)b;
    return **a2 - **b2;
}

int main(int argc, const char *argv[]) {
    struct String *str = new_String("Hello Worlddddd");
    struct String str2 = String("This is a test");
    struct String str3 = String("Hope it works");
    struct Vector vec = Vector(sizeof(struct String), 0);
    vec.pushBack(&vec, str, sizeof(*str));
    vec.pushBack(&vec, &str2, sizeof(str2));
    vec.pushBack(&vec, &str3, sizeof(str3));
    for (int i = 0; i < vec.size; i++) {
        struct String *str = (struct String *)vec.data[i];
        printf("%s\n", str->data);
    }
    printf("---------------------\n");
    struct String str4 = String("This is a new string");
    vec.insert(&vec, &str4, sizeof(struct String), 1);
    for (int i = 0; i < vec.size; i++) {
        struct String *str = (struct String *)vec.data[i];
        printf("%s\n", str->data);
    }
    printf("---------------------\n");
    vec.remove(&vec, 1);
    for (int i = 0; i < vec.size; i++) {
        struct String *str = (struct String *)vec.data[i];
        printf("%s\n", str->data);
    }
    printf("---------------------\n");
    _Vector(&vec);
    _String(str);
    free(str);
    _String(&str2);
    _String(&str3);
    _String(&str4);

    struct Vector vec2 = Vector(sizeof(void *), 0);
    vec2.pushBack(&vec2, &(int){2}, sizeof(int *));
    vec2.pushBack(&vec2, &(int){8}, sizeof(int *));
    vec2.pushBack(&vec2, &(int){3}, sizeof(int *));

    for (int i = 0; i < vec2.size; i++) {
       int *str = (int *)vec2.data[i];
        printf("%d\n", *str);
    }
    printf("---------------------\n");

    vec2.sort(&vec2, cmp);

    for (int i = 0; i < vec2.size; i++) {
       int *str = (int *)vec2.data[i];
        printf("%d\n", *str);
    }
    printf("---------------------\n");
    _Vector(&vec2);

    struct String concStr = String("Hello Worlddddd");
    struct String concStr2 = String("This is a test");
    struct String concStr3 = String("Hope it works");

    struct Vector concVec = Vector(sizeof(struct String), 0);
    concVec.pushBack(&concVec, &concStr, sizeof(concStr));
    concVec.pushBack(&concVec, &concStr2, sizeof(concStr2));
    concVec.pushBack(&concVec, &concStr3, sizeof(concStr3));

    struct Vector concVec2 = Vector(sizeof(struct String), 0);
    concVec2.pushBack(&concVec2, &concStr, sizeof(concStr));
    concVec2.pushBack(&concVec2, &concStr2, sizeof(concStr2));

    struct Vector concVec3 = concVec.concat(&concVec, &concVec2);
    
    for (int i = 0; i < concVec3.size; i++) {
        struct String *str = (struct String *)concVec3.data[i];
        printf("%s\n", str->data);
    }
    printf("---------------------\n");

    _Vector(&concVec);
    _Vector(&concVec2);
    _Vector(&concVec3);

    _String(&concStr);
    _String(&concStr2);
    _String(&concStr3);
    
    concVec = Vector(sizeof(char *), 0);
    concVec.pushBack(&concVec, &"Hello", sizeof(char) * 6);
    concVec.pushBack(&concVec, &"Debut", sizeof(char) * 6);
    concVec.pushBack(&concVec, &"de", sizeof(char) * 3);

    concVec2 = Vector(sizeof(char *), 0);
    concVec2.pushBack(&concVec2, &"phrase", sizeof(char) * 7);
    concVec2.pushBack(&concVec2, &"simple", sizeof(char) * 7);

    concVec3 = concVec.concat(&concVec, &concVec2);

    for (int i = 0; i < concVec3.size; i++) {
        char *str = (char *)concVec3.data[i];
        printf("%s\n", str);
    }
    printf("---------------------\n");

    concVec3.reverse(&concVec3);

    for (int i = 0; i < concVec3.size; i++) {
        char *str = (char *)concVec3.data[i];
        printf("%s\n", str);
    }
    printf("---------------------\n");

    _Vector(&concVec);
    _Vector(&concVec2);
    _Vector(&concVec3);


    struct List list = List(sizeof(struct String));
    str = new_String("Test");
    str2 = String("avec");
    str3 = String("String");

    list.pushBack(&list, str, sizeof(struct String));
    list.pushBack(&list, &str2, sizeof(struct String));
    list.pushBack(&list, &str3, sizeof(struct String));

    printList(&list);

    str4 = String("insert");
    list.insert(&list, &str4, sizeof(struct String), 1);

    printList(&list);

    list.remove(&list, 1);

    printList(&list);

    struct List list2 = List(sizeof(struct String));
    list2.pushBack(&list2, str, sizeof(struct String));
    list2.pushBack(&list2, &str2, sizeof(struct String));
    list2.pushBack(&list2, &str3, sizeof(struct String));

    struct List list3 = list.concat(&list, &list2);

    printList(&list3);

    list3.reverse(&list3);

    printList(&list3);

    _List(&list);
    _List(&list2);
    _List(&list3);
    _String(str);
    _String(&str2);
    _String(&str3);
    _String(&str4);
    free(str);
    return 0;
}