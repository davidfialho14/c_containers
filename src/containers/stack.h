#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef struct List Stack;

Stack* Stack_new();
void Stack_delete(Stack* stack, void (*delete)(void*));

void Stack_add(Stack* stack, Item item);
Item Stack_get(Stack* stack);
Item Stack_peek(Stack* stack);
void Stack_pop(Stack* stack, void (*delete)(void*));

size_t Stack_size(const Stack* stack);
bool Stack_isEmpty(const Stack* stack);


#endif //STACK_H
