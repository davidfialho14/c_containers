#include <malloc.h>
#include "queue.h"

Queue* Queue_new() {
    return List_new();
}

void Queue_delete(Queue* queue, void (* delete)(void*)) {
    return List_delete(queue, NULL);
}

void Queue_add(Queue* queue, Item item) {
    List_insertFront(queue, item);
}

Item Queue_get(Queue* queue) {
    return List_removeBack(queue);
}

Item Queue_peek(Queue* queue) {
    return List_back(queue);
}

void Queue_pop(Queue* queue, void (* delete)(void*)) {

    if(delete == NULL) {
        // use as default the free function
        delete = free;
    }

    Item item = List_removeBack(queue);
    delete(item);
}

size_t Queue_size(const Queue* queue) {
    return List_size(queue);
}

bool Queue_isEmpty(const Queue* queue) {
    return List_isEmpty(queue);
}
