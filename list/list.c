#include "list.h"
#include "../string/string.h"

inline struct List List(size_t type)
{
    struct List list = {
        .pushBack = (&pushBackNode),
        .popBack = (&popBackNode),
        .concat = (&concatList),
        .insert = (&insertNode),
        .remove = (&removeNode),
        .size = (&sizeList),
        .head = NULL,
        .tail = NULL,
    };
    return list;
}

inline void _List(struct List *this)
{
    if (this->head != NULL) {
        struct Node *tmp = this->head;
        while (tmp != NULL) {
            struct Node *tmp2 = tmp;
            tmp = tmp->next;
            if (tmp2->data != NULL)
                free(tmp2->data);
            free(tmp2);
        }
    }
}

int sizeList(struct List *this)
{
    int size = 0;
    struct Node *tmp = this->head;
    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return size;
}

int pushBackNode(struct List *this, void *data, int size)
{
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL)
        return 0;
    node->data = malloc(size);
    if (node->data == NULL)
        return 0;
    memcpy(node->data, data, size);
    node->size = size;
    node->next = NULL;
    if (this->head == NULL) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->next = node;
        this->tail = node;
    }
    return 1;
}

int popBackNode(struct List *this)
{
    if (this->head == NULL)
        return 0;
    struct Node *tmp = this->head;
    while (tmp->next != this->tail)
        tmp = tmp->next;
    free(this->tail->data);
    free(this->tail);
    this->tail = tmp;
    this->tail->next = NULL;
    return 1;
}

struct List concatList(struct List *this, struct List *toAdd)
{
    struct List list = List(0);
    struct Node *tmp = this->head;
    while (tmp != NULL) {
        list.pushBack(&list, tmp->data, tmp->size);
        tmp = tmp->next;
    }
    tmp = toAdd->head;
    while (tmp != NULL) {
        list.pushBack(&list, tmp->data, tmp->size);
        tmp = tmp->next;
    }
    return list;
}

int insertNode(struct List *this, void *data, int size, int index)
{
    if (index < 0 || index > sizeList(this))
        return 0;
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL)
        return 0;
    node->data = malloc(size);
    if (node->data == NULL)
        return 0;
    memcpy(node->data, data, size);
    node->size = size;
    node->next = NULL;
    if (index == 0) {
        node->next = this->head;
        this->head = node;
    } else {
        struct Node *tmp = this->head;
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->next;
        node->next = tmp->next;
        tmp->next = node;
    }
    return 1;
}

int removeNode(struct List *this, int index)
{
    if (index < 0 || index > sizeList(this))
        return 0;
    if (index == 0) {
        struct Node *tmp = this->head;
        this->head = this->head->next;
        free(tmp->data);
        free(tmp);
    } else {
        struct Node *tmp = this->head;
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->next;
        struct Node *tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp2->data);
        free(tmp2);
    }
    return 1;
}

int printList(struct List *this)
{
    struct Node *tmp = this->head;
    while (tmp != NULL) {
        struct String *stmp = (struct String *)tmp->data;
        printf("%s\n", stmp->data);
        tmp = tmp->next;
    }
    printf("---------------------\n");
    return 1;
}