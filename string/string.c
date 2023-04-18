/*
** EPITECH PROJECT, 2022
** LIBCC
** File description:
** string
*/

#include "string.h"

/**
 * It creates a new String object and initializes it with the given char array
 * 
 * @param arr The string to be copied into the struct.
 * 
 * @return A struct String
 */
inline struct String String(const char *arr) {
    struct String string;
    string.size = (&sizeString);
    string.empty = (&emptyString);
    string.append =(&appendString);
    string.back = (&backString);
    string.front = (&frontString);
    string.compare = (&compareString);
    string.c_str = (&c_strString);
    string.clear = (&clearString);
    string.substr = (&substrString);
    string.replace = (&replaceString);
    string.insert = (&insertString);
    string.erase = (&eraseString);
    string.find = (&findString);
    if (arr != NULL) {
        string.data = malloc(sizeof(char) * my_strlen(arr) + 1);
        strcpy(string.data, arr);
    }
    return string;
}

/**
 * It creates a new String object and initializes all of its function pointers to the appropriate
 * functions
 * 
 * @param arr The string to be copied into the String object.
 * 
 * @return A pointer to a struct String
 */
struct String *new_String(const char *arr) {
    struct String *string = malloc(sizeof(struct String));
    string->size = (&sizeString);
    string->empty = (&emptyString);
    string->append =(&appendString);
    string->back = (&backString);
    string->front = (&frontString);
    string->compare = (&compareString);
    string->c_str = (&c_strString);
    string->clear = (&clearString);
    string->substr = (&substrString);
    string->replace = (&replaceString);
    string->insert = (&insertString);
    string->erase = (&eraseString);
    string->find = (&findString);
    if (arr != NULL) {
        string->data = malloc(sizeof(char) * my_strlen(arr) + 1);
        strcpy(string->data, arr);
    }
    return string;
}

/**
 * `_String` frees the memory allocated to the `data` member of the `String` struct
 * 
 * @param this The pointer to the object.
 * 
 * @return The size of the string.
 */
int _String(struct String *this) {
    if (this->size(this) != -1) {
        free(this->data);
    }
    return 0;
}

/**
 * It takes two strings, and appends the second string to the first
 * 
 * @param this The String object that the function is being called on.
 * @param string The string to append to the current string.
 * 
 * @return the size of the string.
 */
void appendString(struct String *this, struct String *string) {
    if (this->size(this) == -1 || string->size(string) == -1)
        return;
    int sizeDest = (this->size(this) + string->size(this));
    char *new = malloc(sizeof(char) * (this->size(this) + string->size(this)));
    int i;
    for (i = 0; this->data[i]; i++) {
        new[i] = this->data[i];
    }
    for (int l = 0; string->data[l]; l++) {
        new[i++] = string->data[l];
    }
    new[i++] = '\0';
    free(this->data);
    this->data = new;
}

/**
 * Return the length of the string, or -1 if the string is NULL.
 * 
 * @param this a pointer to the String object
 * 
 * @return The length of the string.
 */
int sizeString(struct String *this) {
    if (this->data == NULL)
        return -1;
    return strlen(this->data);
}

/**
 * If the string is empty, return 1, otherwise return 0.
 * 
 * @param this The String object that is being called.
 * 
 * @return 1 if the string is empty, 0 if it is not.
 */
int emptyString(struct String *this) {
    if (this->data == NULL || strlen(this->data) == 0)
        return 1;
    return 0;
}

/**
 * If the string is empty, return 0, otherwise return the last character in the string.
 * 
 * @param this The pointer to the String object.
 * 
 * @return The last character in the string.
 */
char backString(struct String *this) {
    if (this->size(this) == -1)
        return 0;
    return this->data[this->size(this) - 1];
}

/**
 * Return the first character of the string, or 0 if the string is empty.
 * 
 * @param this The pointer to the String object.
 * 
 * @return The first character of the string.
 */
char frontString(struct String *this) {
    if (this->size(this) == -1)
        return 0;
    return this->data[0];
}

/**
 * If the two strings are the same size, then compare each character in the string to see if they are
 * the same. If they are, then return 1, otherwise return 0
 * 
 * @param this The String object that is calling the function.
 * @param toCompare The string to compare to.
 * 
 * @return a pointer to a function.
 */
int compareString(struct String *this, struct String *toCompare) {
    if (this->size(this) == toCompare->size(toCompare)) {
        for (int i = 0; this->data[i]; i++) {
            if (this->data[i] != toCompare->data[i])
                return 0;
        }
        return 1;
    }
    return 0;
}

/**
 * Return the C string representation of the String object.
 * 
 * @param this a pointer to the String object
 * 
 * @return A pointer to the first character in the string.
 */
const char * c_strString(struct String *this) {
    const char *res = this->data;
    return res;
}

/**
 * It frees the memory allocated to the string, allocates a new block of memory for the string, and
 * sets the first character of the string to the null character
 * 
 * @param this The pointer to the String object.
 */
void clearString(struct String *this) {
    free(this->data);
    this->data = malloc(sizeof(char));
    this->data[0] = '\0';
}

/**
 * It takes a string, a starting position, and a length, and returns a substring of the original string
 * starting at the starting position and of length len
 * 
 * @param this The String object that is calling the function.
 * @param posStart The starting position of the substring.
 * @param len The length of the substring to be returned.
 * 
 * @return A struct String
 */
struct String substrString(struct String *this, int posStart, int len) {
    struct String res = String(NULL);
    if (posStart < 0 || posStart >= this->size(this))
        return String("");
    int i;
    res.data = malloc(sizeof(char) * (len) + 1);
    for (i = 0; this->data[posStart] && i < len; i++) {
        res.data[i] = this->data[posStart++];
    }
    res.data[i] = '\0';
    return res;
}

/**
 * It replaces a part of the string with another string
 * 
 * @param this The String object that is calling the function.
 * @param posStart The position to start replacing from.
 * @param len The length of the string to be replaced.
 * @param replaceString The string to replace the current string with.
 * 
 * @return A struct String
 */
struct String replaceString(struct String *this, int posStart, int len, struct String *replaceString) {
    struct String res = String(NULL);
    if (posStart < 0 || posStart >= this->size(this))
        return String("");
    int i, l = 0, tmp = 0;
    res.data = malloc(sizeof(char) * (len + this->size(this)) + 1);
    for (i = 0; this->data[l] && i < posStart; i++) {
        res.data[i] = this->data[l++];
    }
    for (i = i; replaceString->data[tmp]; i++) {
        res.data[i] = replaceString->data[tmp++];
    }
    for (l = l + len; this->data[l]; i++) {
        res.data[i] = this->data[l++];
    }
    res.data[i] = '\0';
    return res;
}

/**
 * It takes a string, a position to start inserting at, and a string to insert, and returns a new
 * string with the inserted string in it
 * 
 * @param this The string to insert into.
 * @param posStart The position to start inserting the string at.
 * @param insertString The string to insert
 * 
 * @return A struct String
 */
struct String insertString(struct String *this, int posStart, struct String *insertString) {
    struct String res = String(NULL);
    int len = insertString->size(insertString);
    if (posStart < 0)
        return String("");
    int i, l = 0, tmp = 0;
    res.data = malloc(sizeof(char) * (len + this->size(this)) + 1);
    for (i = 0; this->data[l] && i < posStart; i++) {
        res.data[i] = this->data[l++];
    }
    for (i = i; insertString->data[tmp]; i++) {
        res.data[i] = insertString->data[tmp++];
    }
    for (l = l; this->data[l]; i++) {
        res.data[i] = this->data[l++];
    }
    res.data[i] = '\0';
    return res;
}

/**
 * It takes a string, a starting position, and a length, and returns a new string with the characters
 * from the starting position to the length removed
 * 
 * @param this The String object that the function is being called on.
 * @param posStart The position to start erasing from.
 * @param len The length of the string to be erased.
 * 
 * @return A struct String
 */
struct String eraseString(struct String *this, int posStart, int len) {
    struct String res = String(NULL);
    if (posStart < 0 && posStart + len > this->size(this))
        return String("");
    res.data = malloc(sizeof(char) * (this->size(this) - len) + 1);
    int i;
    for (int l = 0; l < posStart; i++) {
        res.data[i] = this->data[l++];
    }
    for (int l = posStart + len; this->data[l]; i++) {
        res.data[i] = this->data[l++];
    }
    return res;
}

/**
 * Find the first occurrence of the string toFind in this and return the index of the first character
 * of the first occurrence of toFind in this.
 * 
 * @param this the String object that the function is being called on
 * @param toFind The string to find.
 * 
 * @return The index of the first character of the substring.
 */
int findString(struct String *this, struct String *toFind) {
    char *ptr = strstr(this->data, toFind->data);
    int res = ptr - this->data;
    return res;
}