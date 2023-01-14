#include <stdio.h>
#include "singly_list.h"

#define N 10

int main() {
    SinglyList *list = NULL;

    for (int i = 0; i < N; ++i) {
        singly_list_insert_head(&list, i+1);
    }

    singly_list_insert_tail(&list, 11);
    singly_list_insert(&list, NULL, 12);
    singly_list_insert(&list, singly_list_search_previous(list, 12), 100);
    singly_list_insert(&list, singly_list_search(list, 1), 8273);
    singly_list_remove(&list, 100);
    singly_list_remove(&list, 9);
    singly_list_remove(&list, 10000);

    singly_list_print(list);

    singly_list_delete(&list);
}
