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

    printf("FIRST PRINT\n");
    for(ListIterator it = List_begin(list); it != List_end(list); it = List_next(it)) {
        int* number = List_item(it);
        printf("%d\n", *number);
    }

    for(int i = 0; i < 10; i++) {
        int* number = malloc(sizeof(int));
        *number = i;
        List_insertFront(list, number);
    }

    printf("SECOND PRINT\n");
    for(ListIterator it = List_reverseBegin(list); it != List_reverseEnd(list); it = List_previous(it)) {
        int* number = List_item(it);
        printf("%d\n", *number);
    }

    List_delete(list, NULL);

    return 0;
}