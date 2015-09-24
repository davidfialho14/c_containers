#include <malloc.h>
#include "list.h"

typedef struct Element {
    Item item;
    struct Element* next;
    struct Element* previous;
} Element;

struct List {
    Element* front;
    Element* back;
    size_t size;
};

List* List_new() {
    // create list structure
    List* list = malloc(sizeof(List));
    // setup empty list
    list->front = list->back = NULL;
    list->size = 0;

    return list;
}

void List_delete(List* list, void (*delete)(void*)) {

    if(delete == NULL) {
        // use the default free function to delete the items
        delete = free;
    }

    Element* aux = list->front;
    // remove each element in the list
    while(aux != NULL) {
        // move front of the list to the next element
        list->front = aux->next;

        // delete the item
        delete(aux->item);
        // delete the element
        free(aux);

        // move to next element pointed by the fron pointer
        aux = list->front;
    }
}

void List_insertFront(List* list, Item item) {
    // create an list element to hold the item
    Element* element = malloc(sizeof(Element));
    element->item = item;
    element->previous = NULL;

    if(list->front == NULL) {
        // list is empty -> inserting first item
        list->back = element;
        element->next = NULL;
    } else {
        // list is not empty -> link the element to the front element of the list
        element->next = list->front;
        list->front->previous = element;
    }

    // insert element in the front
    list->front = element;
    // increase list size by 1
    list->size++;
}

void List_insertBack(List* list, Item item) {
    // create an list element to hold the item
    Element* element = malloc(sizeof(Element));
    element->item = item;
    element->next = NULL;

    if(list->back == NULL) {
        // list is empty -> inserting first element
        list->front = element;
        element->previous = NULL;
    } else {
        // list is not empty -> link back element to the new element
        list->back->next = element;
        element->previous = list->back;
    }

    // insert element in the back
    list->back = element;
    // increase list size by 1
    list->size++;
}

Item List_removeFront(List* list) {
    Item itemRemoved = NULL;

    if(list->front != NULL) {
        // list is not empty -> remove front element

        if(list->front == list->back) {
            // removing last element in the list -> last pointer must point to NULL
            list->back = NULL;
        }

        // store the front element in aux
        Element* aux = list->front;
        // move the front pointer to the next element in the list
        list->front = list->front->next;
        // the new front element has no previous element
        list->front->previous = NULL;

        // return the item being removed
        itemRemoved = aux->item;
        // delete the element
        free(aux);

        // decrease list size by 1
        list->size--;
    }

    return itemRemoved;
}

Item List_removeBack(List* list) {
    Item itemRemoved = NULL;

    if(list->back != NULL) {
        // list is not empty -> remove back element

        if(list->front == list->back) {
            // removing last element in the list -> front pointer must point to NULL
            list->front = NULL;
        }

        // store the back element in aux
        Element* aux = list->back;
        // move the back pointer to the previous element in the list
        list->back = list->back->previous;
        // new back element has no next element
        list->back->next = NULL;

        // return the item being removed
        itemRemoved = aux->item;
        // delete the element
        free(aux);

        // decrease list size by 1
        list->size--;
    }

    return itemRemoved;
}

Item List_front(List* list) {
    return list->front->item;
}

Item List_back(List* list) {
    return list->back->item;
}

size_t List_size(List* list) {
    return list->size;
}

bool List_isEmpty(List* list) {
    return list->front == NULL;
}
