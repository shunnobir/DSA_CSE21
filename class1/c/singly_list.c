#include "singly_list.h"

#include <stdlib.h>
#include <stdio.h>

Node *node_new(int data) {    
    Node *node = (Node*)malloc(sizeof(struct Node));
    node->next = NULL;
    node->data = data;
    return node;
}

void singly_list_insert_head(SinglyList **list, int data) {
    Node *head = *list;
    Node *node = node_new(data);
    node->next = head;
    *list = node;
}

void singly_list_insert_tail(SinglyList **list, int data) {
    Node *head = *list;
    while (head->next != NULL) {
        head = head->next;
    }

    Node *node = node_new(data);
    head->next = node;
}

void singly_list_insert(SinglyList **list, Node *afterNode, int data) {
    Node *head = *list;
    Node *node = node_new(data);
    if (afterNode == NULL) {
        node->next = head;
       *list = node;
    } else {
        node->next = afterNode->next;
        afterNode->next = node;
    }
}

Node *singly_list_search(SinglyList *list, int key) {
    Node *head = list;
    while (head != NULL && head->data != key) {
        head = head->next;
    }

    return head;
}

Node *singly_list_search_previous(SinglyList *list, int key) {
    Node *head = list;

    if (head != NULL && head->data == key) {
        return NULL;
    }

    while (head != NULL && head->next != NULL && head->next->data != key) {
        head = head->next;
    }

    if (head == NULL || head->next == NULL)  {
        Node *dummy = node_new(-1);
        dummy->next = dummy;
        return dummy;
    }
    return head;
}

void singly_list_remove(SinglyList **list, int key) {
    Node *previousNode = singly_list_search_previous(*list, key);
    if (previousNode == NULL) {
        Node *head = *list;
        *list = head->next;
        free(head);
    } else if (previousNode->next != previousNode) {
        printf("%p %d %p\n", previousNode, previousNode->data, previousNode->next);
        Node *next = previousNode->next;
        previousNode->next = next->next;
        free(next);
    } else {
        free(previousNode);
    }
}

void singly_list_print(SinglyList *list) {
    if (list == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", list->data);
    singly_list_print(list->next);
}

void singly_list_delete(SinglyList **list) {
    Node *head = (*list);
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    } 
}
