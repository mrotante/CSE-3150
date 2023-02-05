#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

struct node {
    int number;
    struct node* next;
};

struct node* build_linked_list(int elements);
void print_linked_list(struct node* list, int elements);
int delete_linked_list(struct node* list, int elements);
int sum_values_in_linked_list(struct node* list, int elements);

#endif