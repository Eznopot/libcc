/*
** LIBCC
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdbool.h>

int my_strlen(const char *string);
char **f_str_to_array(const char *str, char to_split, bool include);

#define f_str_to_array2(...) f_str_to_array(__VA_ARGS__, '\n')
#define f_str_to_array1(...) f_str_to_array2(__VA_ARGS__, true)
#define VAR_FUNC_ARR(_1, _2, _3, NAME, ...) NAME
#define str_to_array(...) VAR_FUNC_ARR(__VA_ARGS__, f_str_to_array, f_str_to_array2, f_str_to_array1)(__VA_ARGS__)

#endif /* !INCLUDE_H_ */
