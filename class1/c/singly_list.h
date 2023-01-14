#ifndef __SINGLY_LIST__
#define __SINGLY_LIST__

// Main node structure, typedefed as SinglyList
typedef struct Node {
    int data;
    struct Node *next;
} SinglyList;

// Creating another alias for the Node structure for convinience
typedef struct Node Node;

// Helper function to create new nodes
// Complexity: O(1)
Node *node_new();

// Inserts data at the head of the list
// Complexity: O(1)
void singly_list_insert_head(SinglyList **list, int data);

// Inserts data at the tail of the list
// Complexity: O(N)
void singly_list_insert_tail(SinglyList **list, int data);


// Inserts data after the afterNode
// Complexity: O(1)
void singly_list_insert(SinglyList **list, Node *afterNode, int data);


// Searches for the node with the key from the list and returns the node
// Complexity: O(N)
Node *singly_list_search(SinglyList *list, int key);

// Searches for the previous node of the node with the key from the list and returns it
// Complexity: O(N)
Node *singly_list_search_previous(SinglyList *list, int key);

// Prints the whole list
// Complexity: O(N)
void singly_list_print(SinglyList *list);

// Removes the node with the key from the list
// Complexity: O(N)
void singly_list_remove(SinglyList **list, int key);

// Deletes the whole list and free's all the memory being allocated
// Complexity: O(N)
void singly_list_delete(SinglyList **list);

#endif
