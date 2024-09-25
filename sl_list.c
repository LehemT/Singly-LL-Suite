/**
 * @file sl_list.c
 * @author Lehem Temesgen
 * @version 12/01/2023
 * @brief An implementation for singly linked list operations and tests.
 * 
 * This file contains the implementations of core functionalities for 
 * manipulating singly linked lists, including adding/removing nodes 
 * at specific positions, counting occurrences of a specific value, 
 * retrieving the last value in the list, etc.
*/

#include <assert.h>             
#include <stdlib.h>             
#include <stdbool.h>
#include <stdio.h>              

#include "sl_list.h"


/* Return a pointer to a new intnode_t (a node in a singly-linked list).

   Value is the integer to be stored in the node, and Next is the pointer 
   to the node that the new node should point to. This pointer should be NULL 
   if the new node is the last node in the linked list.
   Terminate (via assert) if memory for the node cannot be allocated.
 */
intnode_t *intnode_construct(int value, intnode_t *next)
{
    intnode_t *p = malloc(sizeof(intnode_t));
    assert(p != NULL);
    p->value = value;
    p->next = next;
    return p;
}

/* Head points to the first node in a linked list, or is NULL
   if the linked list is empty. Insert a node containing the specified 
   integer value at the front of the linked list, and return a pointer to 
   the first node in the modified list.
 */
intnode_t *push(intnode_t *head, int value)
{
    return intnode_construct(value, head);
}

/* Head points to the first node in the list.
   Return the length of a linked list (0 if the linked list is empty). 
 */
int length(intnode_t *head)
{
    int count = 0;
    for (intnode_t * current = head; current != NULL; current = current->next) {
        count += 1;
    }
    return count;
}

/* Head points to the first node in a linked list.
   Print the linked list, using the format: value1 -> value2 -> ... -> last_value
 */
void print_list(intnode_t *head)
{
    if (head == NULL) {
        printf("empty list");
        return;
    }

    intnode_t *current;

    // Print every node in the linked list except the last one
    for (current = head; current->next != NULL; current = current->next) {
        printf("%d -> ", current->value);
    }

    /* Print the last node. */
    printf("%d", current->value);
}


intnode_t *add(intnode_t *head, int elem, int index)
{
    intnode_t *new_node = intnode_construct(elem, NULL);

    // insert at the front or end of the linked list
    if (index == 0 || head == NULL) {
        new_node->next = head;
        return new_node;
    }

    intnode_t *current = head;
    int i = 0;

    while (current->next != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    // insert at specific position
    new_node->next = current->next;
    current->next = new_node;

    return head;
}


void every_other(intnode_t *head)
{
    if (head == NULL || head->next == NULL) {   // do nothing if empty or single-node list
        return;
    }

    intnode_t *current = head;
    intnode_t *next_node;

    while (current != NULL && current->next != NULL) {
        next_node = current->next;   // save the next node before deleting the current one
        
        current->next = next_node->next;    // adjust pointers to skip the next node
        
        free(next_node);    // free the memory of the deleted node

        current = current->next;    // move to the next node, skipping the deleted node
    }
}


/* Return the count of the number of times target occurs in the 
 * linked list pointed to by head. 
 */
int count_in_sll(intnode_t *head, int target)
{
    if (head == NULL) {    // empty list
        return 0;
    }

    int count = count_in_sll(head->next, target);

    // check if the current node's value is equal to the target
    if (head->value == target) {
        count++;
    }

    return count;
}


/* Return the last element in the linked list pointed to by head.
 * Terminate (via assert) if the list is empty.
 */
int last_in_sll(intnode_t *head)
{
    assert(head != NULL);    // empty list

    if (head->next == NULL) {    // last node
        return head->value;
    }

    return last_in_sll(head->next);    // move to the next node
}
