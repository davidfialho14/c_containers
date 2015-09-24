#include <stdio.h>
#include <malloc.h>
#include "containers/list.h"

int main() {

    List* list = List_new();

    for(int i = 0; i < 10; i++) {
        int* number = malloc(sizeof(int));
        *number = i;
        List_insertBack(list, number);
    }

    for(ListIterator it = List_begin(list); it != List_end(list); it = List_next(it)) {
        int* number = List_item(it);
        printf("%d\n", *number);
    }

    List_delete(list, NULL);

    return 0;
}