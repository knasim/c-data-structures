/**
 * @brief Circular linked list structure and methods
 * @file circular_linked_list.h
 */

typedef struct LinkedListNode LinkedListNode;

typedef struct CircularLinkedList
{
    struct LinkedListNode* last;
} CircularLinkedList;

/**
 * @brief Creates a new circular linked list with one node
 *
 * @param data integer to set into the new created node
 *
 * @return CircularLinkedList
 */
CircularLinkedList createCLL(const int data);

/**
 * @brief Inserts one node at the end of the list
 *
 * @param list the circular linked list to update
 * @param data the new data to insert
 */
void insertAtTheEndCLL(
    CircularLinkedList* list,
    const int data
);
