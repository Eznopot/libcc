#include "vector.h"

/**
 * The function creates a new Vector struct and initializes its properties with function pointers.
 * 
 * @param type The "type" parameter in the function "Vector" is used to specify the data type of the
 * elements that will be stored in the vector. It is of type "size_t", which is an unsigned integer
 * type used to represent the size of objects in bytes.
 * 
 * @return A struct Vector object is being returned.
 */
inline struct Vector Vector(size_t type) {
    struct Vector vector;
    vector.type = type;
    vector.sizeElem = NULL;
    vector.data = NULL;
    vector.pushBack = (&pushBackElem);
    vector.popBack = (&popBackElem);
    vector.insert = (&insertElem);
    vector.remove = (&removeElem);
    vector.concat = (&concatVector);
    vector.size = (&sizeVector);
    return vector;
}

/**
 * The function frees the memory allocated for the data array in a Vector struct.
 * 
 * @param this The parameter "this" is a pointer to a struct Vector. It is used to refer to the current
 * instance of the struct Vector within the function.
 */
void _Vector(struct Vector *this) {
    if (this->data != NULL) {
        for (int i = 0; this->data[i]; i++) {
            free(this->data[i]);
        }
        free(this->data);
    }
    if (this->sizeElem != NULL)
        free(this->sizeElem);
}

/**
 * The function returns the size of a vector by iterating through its data array.
 * 
 * @param this The parameter "this" is a pointer to a struct Vector. It is used to access the data
 * stored in the Vector structure.
 * 
 * @return The function `sizeVector` returns the number of elements in the vector represented by the
 * `struct Vector` pointer `this`. If the vector is empty (i.e., `this->data` is `NULL`), the function
 * returns `-1`.
 */
int sizeVector(struct Vector *this) {
    int i;

    if (this->data == NULL)
        return -1;
    for (i = 0; this->data[i]; i++);
    return i;
}

/**
 * This function adds an element to the end of a dynamic array.
 * 
 * @param this a pointer to a struct Vector, which contains information about the vector (such as its
 * size and data)
 * @param data A pointer to the data that needs to be added to the vector.
 * @param size The size parameter in the pushBackElem function is the size of the data being added to
 * the vector. It is used to allocate memory for the new element being added to the vector.
 * 
 * @return an integer value. If the data parameter is NULL, it returns -1 indicating an error.
 * Otherwise, it returns 0 indicating success.
 */
int pushBackElem(struct Vector *this, void *data, int size) {
    if (data == NULL)
        return -1;
    if (this->data == NULL) {
        this->data = malloc(sizeof(void *) * (2));
        this->data[0] = malloc(size);
        memcpy(this->data[0], data, size);
        this->data[1] = NULL;
        this->sizeElem = malloc(sizeof(int));
        this->sizeElem[0] = size;
    } else {
        int len = this->size(this);
        this->data = realloc(this->data, sizeof(void *) * (len + 2));
        this->data[len] = malloc(size);
        memcpy(this->data[len], data, size);
        this->data[len + 1] = NULL;
        this->sizeElem = realloc(this->sizeElem, sizeof(int) * (len + 1));
        this->sizeElem[len] = size;
    }
    return 0;
}

/**
 * This function removes the last element from a vector and frees its memory.
 * 
 * @param this The parameter "this" is a pointer to a struct Vector, which is a user-defined data
 * structure that represents a dynamic array. The function popBackElem() is a member function of this
 * struct, which means it operates on an instance of the struct that is passed as the "this" parameter.
 * 
 * @return an integer value. If the operation is successful, it returns 0. If there is an error, it
 * returns -1.
 */
int popBackElem(struct Vector *this) {
    if (this->data == NULL)
        return -1;
    int len = this->size(this);
    if (len == 0)
        return -1;
    free(this->data[len - 1]);
    this->data = realloc(this->data, sizeof(void *) * (len));
    this->data[len - 1] = NULL;
    this->sizeElem = realloc(this->sizeElem, sizeof(int) * (len - 1));
    return 0;
}

/**
 * The function concatenates two vectors of the same type and returns a new vector containing all the
 * elements of both input vectors. /!\ The function does not work with char * and int *.
 * 
 * @param this The "this" parameter is a pointer to a struct Vector object, which represents the vector
 * that the function is being called on.
 * @param toAdd The "toAdd" parameter is a pointer to a struct Vector that represents the vector to be
 * concatenated with the "this" vector.
 * 
 * @return The function `concatVector` returns a new `Vector` that is the concatenation of two input
 * `Vector` objects.
 */
struct Vector concatVector(struct Vector *this, struct Vector *toAdd) {
    if (this->type != toAdd->type) // si les type sont differents alors on return un vector vide
        return Vector(this->type);
    struct Vector res = Vector(this->type);
    int l = 0;
    int len = this->size(this) + this->size(toAdd);
    res.data = malloc(sizeof(void *) * len + 1);
    res.sizeElem = malloc(sizeof(int) * len);
    for (int i = 0; this->data[i]; i++) {
        res.data[l] = malloc(this->sizeElem[i]);
        res.sizeElem[l] = this->sizeElem[i];
        memcpy(res.data[l++], this->data[i], this->sizeElem[i]);
    }
    for (int i = 0; toAdd->data[i]; i++) {
        res.data[l] = malloc(toAdd->sizeElem[i]);
        res.sizeElem[l] = toAdd->sizeElem[i];
        memcpy(res.data[l++], toAdd->data[i], toAdd->sizeElem[i]);
    }
    res.data[l] = NULL;
    return res;
}

/**
 * The function inserts an element into a vector at a specified index.
 * 
 * @param this a pointer to a struct Vector object
 * @param data A pointer to the data that needs to be inserted into the vector.
 * @param size The size parameter in the insertElem function refers to the size of the data being
 * inserted into the vector. It is used to allocate memory for the new element being added to the
 * vector.
 * @param index The index parameter in the insertElem function refers to the position at which the new
 * element is to be inserted in the vector. It is an integer value that represents the index of the
 * element in the vector. If the index is 0, the new element will be inserted at the beginning of the
 * vector
 * 
 * @return an integer value. If the insertion is successful, it returns 0. If the data parameter is
 * NULL or if the index is out of bounds, it returns -1.
 */
int insertElem(struct Vector *this, void *data, int size, int index) {
    if (data == NULL)
        return -1;
    if (this->data == NULL && index == 0) {
        this->data = malloc(sizeof(void *) * (2));
        this->data[0] = malloc(size);
        memcpy(this->data[0], data, size);
        this->data[1] = NULL;
        this->sizeElem = malloc(sizeof(int));
        this->sizeElem[0] = size;
    } else if (this->data == NULL && index != 0) {
        return -1;
    } else {
        int len = this->size(this);
        this->data = realloc(this->data, sizeof(void *) * (len + 2));
        for (int i = len; i > index; i--) {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = malloc(size);
        memcpy(this->data[index], data, size);
        this->data[len + 1] = NULL;
        this->sizeElem = realloc(this->sizeElem, sizeof(int) * (len + 1));
        for (int i = len; i > index; i--) {
            this->sizeElem[i] = this->sizeElem[i - 1];
        }
        this->sizeElem[index] = size;
    }
    return 0;
}

/**
 * The function removes an element from a vector at a specified index.
 * 
 * @param this The "this" parameter is a pointer to a struct Vector object, which represents the vector
 * that the function is being called on.
 * @param index The index parameter in the removeElem function refers to the position of the element
 * to be removed from the vector. It is an integer value that represents the index of the element in
 * the vector. If the index is 0, the first element will be removed from the vector.
 * 
 * @return an integer value. If the operation is successful, it returns 0. If the index is out of
 * bounds, it returns -1.
 */

int removeElem(struct Vector *this, int index) {
    if (this->data == NULL)
        return -1;
    int len = this->size(this);
    if (index >= len)
        return -1;
    free(this->data[index]);
    for (int i = index; i < len; i++) {
        this->data[i] = this->data[i + 1];
    }
    this->data = realloc(this->data, sizeof(void *) * (len));
    this->data[len - 1] = NULL;
    for (int i = index; i < len; i++) {
        this->sizeElem[i] = this->sizeElem[i + 1];
    }
    this->sizeElem = realloc(this->sizeElem, sizeof(int) * (len - 1));
    return 0;
}

/**
 * The function iterates through a vector's data and prints its type. only for testing purposes.
 * 
 * @param this The parameter "this" is a pointer to a struct Vector.
 * 
 * @return an integer value of 0.
 */
int test(struct Vector *this) {
    for (int i = 0; this->data[i]; i++) {
        printf("%s\n", (char *)(this->data[i]));
    }
    if (this->type == sizeof(char)) {
        printf("char ");
    }
    if (this->type == sizeof(char *)) {
        printf("char * ");
    }
    if (this->type == sizeof(int)) {
        printf("int ");
    }
    if (this->type == sizeof(int *)) {
        printf("int * ");
    }
    printf("\n\n");
    return 0;
}