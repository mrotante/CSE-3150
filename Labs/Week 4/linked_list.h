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
struct node* array_of_pointers(struct node* first, int elements); //this gets called before pointers get adjusted otherwise will only work on 1 element
void change_pointers(struct node* array, int elements);

#endif