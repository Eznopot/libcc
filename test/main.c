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
    struct String str = String("Hello Worlddddd");
    struct String str2 = String("This is a test");
    struct String str3 = String("Hope it works");

    struct Vector vec = Vector(sizeof(struct String));
    vec.pushBack(&vec, &str, sizeof(str));
    vec.pushBack(&vec, &str2, sizeof(str2));
    vec.pushBack(&vec, &str3, sizeof(str3));

    for (int i = 0; i < vec.size(&vec); i++) {
        struct String *str = (struct String *)vec.data[i];
        printf("%s\n", str->data);
    }
    printf("---------------------\n");

    struct String str4 = String("This is a new string");

    vec.insert(&vec, &str4, sizeof(struct String), 1);

    for (int i = 0; i < vec.size(&vec); i++) {
        struct String *str = (struct String *)vec.data[i];
        printf("%s\n", str->data);
    }

    _Vector(&vec);
    _String(&str);
    _String(&str2);
    _String(&str3);
    _String(&str4);


    struct Vector vec2 = Vector(sizeof(int *));
    vec2.pushBack(&vec2, &(int){1}, sizeof(int *));
    vec2.pushBack(&vec2, &(int){2}, sizeof(int *));
    vec2.pushBack(&vec2, &(int){3}, sizeof(int *));

    for (int i = 0; i < vec2.size(&vec2); i++) {
       int *str = (int *)vec2.data[i];
        printf("%d\n", *str);
    }

    _Vector(&vec2);



    struct String concStr = String("Hello Worlddddd");
    struct String concStr2 = String("This is a test");
    struct String concStr3 = String("Hope it works");

    struct Vector concVec = Vector(sizeof(struct String));
    concVec.pushBack(&concVec, &concStr, sizeof(concStr));
    concVec.pushBack(&concVec, &concStr2, sizeof(concStr2));
    concVec.pushBack(&concVec, &concStr3, sizeof(concStr3));

    struct Vector concVec2 = Vector(sizeof(struct String));
    concVec2.pushBack(&concVec2, &concStr, sizeof(concStr));
    concVec2.pushBack(&concVec2, &concStr2, sizeof(concStr2));

    struct Vector concVec3 = concVec.concat(&concVec, &concVec2);
    
    for (int i = 0; i < concVec3.size(&concVec3); i++) {
        struct String *str = (struct String *)concVec3.data[i];
        printf("%s\n", str->data);
    }


    _Vector(&concVec);
    _Vector(&concVec2);
    _Vector(&concVec3);
    _String(&concStr);
    _String(&concStr2);
    _String(&concStr3);
    
    return 0;
}