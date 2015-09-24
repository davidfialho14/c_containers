#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef struct List Queue;

Queue* Queue_new();
void Queue_delete(Queue* queue, void (*delete)(void*));

void Queue_add(Queue* queue, Item item);
Item Queue_get(Queue* queue, Item item);
Item Queue_peek(Queue* queue, Item item);
void Queue_pop(Queue* queue, void (*delete)(void*));

size_t Queue_size(const Queue* queue);
bool Queue_isEmpty(const Queue* queue);

#endif //QUEUE_H
