#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdbool.h>
#include "list.c"

typedef struct List List;
typedef Element* ListIterator;
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

ListIterator List_begin(const List* list);
ListIterator List_end(const List* list);
ListIterator List_reverseBegin(const List* list);
ListIterator List_reverseEnd(const List* list);
ListIterator List_next(ListIterator iterator);
ListIterator List_previous(ListIterator iterator);
Item List_item(ListIterator iterator);

#endif //LIST_H
