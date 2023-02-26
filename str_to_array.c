/*
** LIBCC
** File description:
** str_to_array
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "include.h"

char **f_str_to_array(const char *str, char to_split, bool included) {
    int nb_raw = 1, i = 0, l = 0, j = 0, a;
    char **res;
    for  (i = 0; str[i]; i++) {
        nb_raw += (str[i] == to_split) ? 1 : 0;
    }
    res = malloc((nb_raw + 1) * sizeof(char *));
    for (i = 0; i < nb_raw; i++) {
        for (l; str[l] != to_split && str[i]; l++);
        l += included ? 1 : 0;
        res[i] = malloc((l - j + 1) * sizeof(char));
        j += i == 0 ? 0 : !included ? 1 : 0;
        for (a = 0; j < l; a++, j++) {
            res[i][a] = str[j];
        }
        res[i][a] = '\0';
        l++;
    }
    res[i] = NULL;
    return res;
}