#ifndef __SINGLY_LIST__
#define __SINGLY_LIST__

#include <iostream>

class SinglyList {
    public:
        struct Node {
            int data;
            Node *next;
        
            Node(int data)
                : data{data}, next{nullptr} { }
        };

    public:
        // Constructor
        SinglyList();
        // Destructor
        ~SinglyList();
    
        void insert_head(int data);

        void insert_tail(int data);

        void insert(Node *afterNode, int data);
        
        Node *search(int key);

        Node *search_previous(int key);

        void remove(int key);

        void print();

    private:
        Node *head{nullptr};

        void print(Node *node) {
            if (node == nullptr) {
                std::cout << "NULL\n";
                return;
            }

            std::cout << node->data << " -> ";
            print(node->next);
        }
};

#endif
