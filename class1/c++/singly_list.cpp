#include "singly_list.h"

#include <iostream>

SinglyList::SinglyList() = default;

SinglyList::~SinglyList() {
    Node *temp = head;
    while (temp != nullptr) {
        Node *g = temp;
        temp = temp->next;
        delete g;
    }
}

void SinglyList::insert_head(int data) {
    Node *node = new Node(data);
    node->next = head;
    head = node; 
}

void SinglyList::insert_tail(int data) {
    Node *t = head;
    while (t->next != nullptr) {
        t = t->next;
    }

    Node *node = new Node(data);
    t->next = node;
}

void SinglyList::insert(Node *afterNode, int data) {
    Node *node = new Node(data);
    if (afterNode == nullptr) {
        node->next = head;
        head = node;
    } else {
        node->next = afterNode->next;
        afterNode->next = node;
    }
}

SinglyList::Node *SinglyList::search(int key) {
    Node *t = head;
    while (t != nullptr && t->data != key) {
        t = t->next;
    }

    return t;
}

SinglyList::Node *SinglyList::search_previous(int key) {
    Node *t = head;
    if (t != nullptr && t->data == key) {
        return nullptr;
    }

    while (t != nullptr && t->next != nullptr && t->next->data != key) {
        t = t->next;
    }

    if (t == nullptr || t->next == nullptr) {
        Node *dummy = new Node(-1);
        dummy->next = dummy;
        return dummy;
    }

    return t;
}

void SinglyList::remove(int key) {
    Node *previousNode = search_previous(key);
    if (previousNode == nullptr) {
        Node *t = head;
        head = t->next;
        delete t;
    } else if (previousNode->next != previousNode) {
        Node *next = previousNode->next;
        previousNode->next = next->next;
        delete next;
    } else {
        delete previousNode;
    }
}

void SinglyList::print() {
    print(head);
}
