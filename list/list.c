#include "list.h"
#include "../string/string.h"

/**
 * The function creates and returns a new List object with initialized function pointers and NULL head
 * and tail pointers.
 * 
 * @param type The parameter "type" is not used in the function and is therefore irrelevant. It can be
 * removed without affecting the functionality of the code.
 * 
 * @return A struct List object is being returned.
 */
inline struct List List(size_t type)
{
    struct List list = {
        .pushBack = (&pushBackNode),
        .popBack = (&popBackNode),
        .concat = (&concatList),
        .insert = (&insertNode),
        .remove = (&removeNode),
        .reverse = (&reverseList),
        .size = (&sizeList),
        .head = NULL,
        .tail = NULL,
    };
    return list;
}

/**
 * The function frees the memory allocated for a linked list and its nodes.
 * 
 * @param this The parameter "this" is a pointer to a struct List object.
 */
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

/**
 * The function calculates the size of a linked list by iterating through its nodes.
 * 
 * @param this The parameter "this" is a pointer to a struct List, which is a user-defined data type
 * representing a linked list. The function "sizeList" takes this pointer as input and returns the size
 * of the linked list, which is the number of nodes in the list.
 * 
 * @return The function `sizeList` returns an integer value which represents the number of nodes in the
 * linked list.
 */
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

/**
 * The function adds a new node with data to the end of a linked list.
 * 
 * @param this a pointer to a struct List, which represents a linked list data structure.
 * @param data A pointer to the data that needs to be added to the list.
 * @param size The size parameter in the pushBackNode function is the size of the data being added to
 * the linked list node. It is used to allocate memory for the node's data and to set the size of the
 * node.
 * 
 * @return an integer value of 1 if the node is successfully added to the end of the linked list, and 0
 * if there is an error in allocating memory for the node or its data.
 */
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

/**
 * The function removes the last node from a linked list and returns 1 if successful, 0 otherwise.
 * 
 * @param this The parameter "this" is a pointer to a struct List, which represents a linked list data
 * structure.
 * 
 * @return an integer value of 1 if the operation of removing the last node from the linked list is
 * successful, and 0 if the linked list is empty.
 */
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

/**
 * The function concatenates two linked lists and returns the resulting list.
 * 
 * @param this The "this" parameter in the function refers to a pointer to a List struct, which
 * represents the first list that we want to concatenate.
 * @param toAdd The "toAdd" parameter is a pointer to a struct List that contains the elements to be
 * added to the end of the "this" list.
 * 
 * @return The function `concatList` is returning a new `List` that contains all the elements of the
 * two input lists (`this` and `toAdd`) concatenated together.
 */
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

/**
 * This function inserts a new node with given data and size at a specified index in a linked list.
 * 
 * @param this The "this" parameter is a pointer to the List structure on which the insertNode function
 * is being called. It allows the function to access the head and size variables of the list.
 * @param data A pointer to the data that needs to be inserted into the list.
 * @param size The size parameter in the insertNode function refers to the size of the data being
 * inserted into the linked list. It is used to allocate memory for the new node's data and to copy the
 * data into the allocated memory using the memcpy function.
 * @param index The index parameter in the insertNode function represents the position in the linked
 * list where the new node should be inserted. If index is 0, the new node will be inserted at the
 * beginning of the list. If index is equal to the size of the list, the new node will be inserted at
 * 
 * @return an integer value, either 0 or 1. A return value of 0 indicates that the node could not be
 * inserted, while a return value of 1 indicates that the node was successfully inserted.
 */
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

/**
 * The function removes a node from a linked list at a specified index.
 * 
 * @param this The "this" parameter is a pointer to a struct List, which represents a linked list data
 * structure.
 * @param index The index parameter represents the position of the node that needs to be removed from
 * the linked list. If the index is less than 0 or greater than the size of the linked list, the
 * function returns 0 indicating that the removal was unsuccessful. Otherwise, the function removes the
 * node at the specified index
 * 
 * @return an integer value of 1 if the node at the specified index is successfully removed from the
 * linked list, and 0 if the index is out of bounds.
 */
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

/**
 * The function reverses the order of nodes in a linked list.
 * 
 * @param this The parameter "this" is a pointer to a struct List, which is a data structure
 * representing a linked list.
 * 
 * @return an integer value of 1 if the list is successfully reversed, and 0 if the list is empty
 * (i.e., the head pointer is NULL).
 */
int reverseList(struct List *this)
{
    if (this->head == NULL)
        return 0;
    struct Node *tmp = this->head;
    struct Node *tmp2 = NULL;
    struct Node *tmp3 = NULL;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        tmp->next = tmp3;
        tmp3 = tmp;
        tmp = tmp2;
    }
    tmp = this->head;
    this->head = this->tail;
    this->tail = tmp;
    return 1;
}

/**
 * The function prints the contents of a linked list of strings. 
 * ! For debug and test only.
 * 
 * @param this The parameter "this" is a pointer to a struct List.
 * 
 * @return The function `printList` is returning an integer value of 1.
 */
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