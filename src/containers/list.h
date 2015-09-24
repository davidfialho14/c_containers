#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct List List;
typedef void* Item;

List* List_new();
void List_delete(List* list, void (*delete)(void*));

void List_insertFront(List* list, Item item);
void List_insertBack(List* list, Item item);
Item List_removeFront(List* list);
Item List_removeBack(List* list);

Item List_front(const List* list);
Item List_back(const List* list);
size_t List_size(const List* list);
bool List_isEmpty(const List* list);

#endif //LIST_H
