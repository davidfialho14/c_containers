#include <malloc.h>
#include "list.h"

typedef struct Element {
    Item item;
    struct Element* next;
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
