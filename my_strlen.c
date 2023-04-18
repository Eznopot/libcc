/*
** LIBCC
** File description:
** my_strlen
*/

int rec_strlen(int index, const char *string) {
    return string[index] ? rec_strlen(++index, string) : index;
}

int my_strlen(const char *string) {
    int i = 0;
    while(string[i++]);
    return i;
}