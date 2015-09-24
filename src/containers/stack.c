#include <malloc.h>
#include "stack.h"

Stack* Stack_new() {
    return List_new();
}

void Stack_delete(Stack* stack, void (* delete)(void*)) {
    return List_delete(stack, NULL);
}

void Stack_add(Stack* stack, Item item) {
    List_insertFront(stack, item);
}

Item Stack_get(Stack* stack) {
    return List_removeFront(stack);
}

Item Stack_peek(Stack* stack) {
    return List_front(stack);
}

void Stack_pop(Stack* stack, void (* delete)(void*)) {

    if(delete == NULL) {
        // use as default the free function
        delete = free;
    }

    Item item = List_removeFront(stack);
    delete(item);
}

size_t Stack_size(const Stack* stack) {
    return List_size(stack);
}

bool Stack_isEmpty(const Stack* stack) {
    return List_isEmpty(stack);
}
