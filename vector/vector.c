#include "vector.h"

inline struct Vector Vector(size_t type) {
    struct Vector vector;
    vector.type = type;
    vector.data = NULL;
    vector.pushBack = (&pushBackElem);
    vector.popBack = (&popBackElem);
    vector.insert = (&insertElem);
    vector.concat = (&concatVector);
    vector.size = (&sizeVector);
    return vector;
}

void _Vector(struct Vector *this) {
    for (int i = 0; this->data[i]; i++) {
        free(this->data[i]);
    }
    free(this->data);
}

int sizeVector(struct Vector *this) {
    int i;

    if (this->data == NULL)
        return -1;
    for (i = 0; this->data[i]; i++);
    return i;
}

int getMallocSize(struct Vector *this) {
    int res = 0;

    if (this->data == NULL)
        return -1;
    for (int i = 0; this->data[i]; i++) {
        res += sizeof(this->data[i]);
    }
    return res;
}

int pushBackElem(struct Vector *this, void *data, int size) {
    if (data == NULL)
        return -1;
    if (this->data == NULL) {
        this->data = malloc(sizeof(void *) * (2));
        this->data[0] = malloc(size);
        memcpy(this->data[0], data, size);
        this->data[1] = NULL;
    } else {
        int len = this->size(this);
        this->data = realloc(this->data, sizeof(void *) * (len + 2));
        this->data[len] = malloc(size);
        memcpy(this->data[len], data, size);
        this->data[len + 1] = NULL;
    }
    return 0;
}

int popBackElem(struct Vector *this) {
    if (this->data == NULL)
        return -1;
    int len = this->size(this);
    if (len == 0)
        return -1;
    free(this->data[len - 1]);
    this->data = realloc(this->data, sizeof(void *) * (len));
    this->data[len - 1] = NULL;
    return 0;
}

struct Vector concatVector(struct Vector *this, struct Vector *toAdd) {
    if (this->type != toAdd->type) // si les type sont differents alors on return un vector vide
        return Vector(this->type);
    struct Vector res = Vector(this->type);
    int l = 0;
    int len = this->size(this) + this->size(toAdd);
    res.data = malloc(sizeof(void *) * len);
    for (int i = 0; this->data[i]; i++) {
        res.data[l] = malloc(sizeof(this->data[i]) * this->type);
        memcpy(res.data[l++], this->data[i], sizeof(this->data[i]));
    }
    for (int i = 0; toAdd->data[i]; i++) {
        res.data[l] = malloc(sizeof(toAdd->data[i]) * toAdd->type);
        memcpy(res.data[l++], toAdd->data[i], sizeof(toAdd->data[i]) * toAdd->type);
    }
    res.data[l] = NULL;
    return res;
}

int insertElem(struct Vector *this, void *data, int size, int index) {
    if (data == NULL)
        return -1;
    if (this->data == NULL && index == 0) {
        this->data = malloc(sizeof(void *) * (2));
        this->data[0] = malloc(size);
        memcpy(this->data[0], data, size);
        this->data[1] = NULL;
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
    }
    return 0;
}

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