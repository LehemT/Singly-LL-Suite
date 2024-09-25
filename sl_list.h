/**
 * @file sl_list.h
 * @author Lehem Temesgen
 * @version 12/01/2023
 * @brief An implementation for singly linked list operations and tests.
 * 
 * This header file contains the declarations for the linked list node 
 * structure and the functions implemented in the program.
*/

#ifndef __SL_LIST_H__
#define __SL_LIST_H__

/* A node in a singly-linked list that stores values of type int. */

typedef struct intnode {
    int    value;
    struct intnode *next;
} intnode_t;


intnode_t *intnode_construct(int value, intnode_t *next);
intnode_t *push(intnode_t *head, int value);
int length(intnode_t *head);
void print_list(intnode_t *head);


intnode_t *add(intnode_t *head, int elem, int index);
void every_other(intnode_t *head);
int count_in_sll(intnode_t *head, int target);
int last_in_sll(intnode_t *head);

#endif