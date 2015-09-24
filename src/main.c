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

    List_delete(list, NULL);

    return 0;
}