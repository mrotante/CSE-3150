#include <iostream>
#include "linked_list.h"

using namespace std;

struct node* build_linked_list(int elements) {
    if(elements == 0) {
        return NULL;
    }

    struct node* head = new node;
    struct node* ptr = head;
    
    for(int i = 0; i < elements; i++) {
        ptr->number = i;
        ptr->next = new node;
        ptr = ptr->next;
        if(i+1 == elements) {
            delete ptr;
        }
    }  
    
    return head;
}

void print_linked_list(struct node* list, int elements) {
    struct node* ptr = list;
    for(int i = 0; i < elements-1; i++) {
        cout << ptr->number << " , ";
        ptr = ptr->next;
    }

    cout << ptr->number << endl;
}

int delete_linked_list(struct node * list, int elements) {
    int count = 0;
  
    struct node * my_node = list;
    for (int i = 0; i < elements; i++) {
        struct node * prev_node = my_node;
        my_node = my_node->next;

        delete prev_node;
        count++;
    }

    return count;
}

int sum_values_in_linked_list(struct node* list, int elements) {
    int sum = 0;
    struct node* ptr = list;

    for(int i = 0; i < elements; i++) {
        sum += ptr->number;
        ptr = ptr->next;
    }

    return sum;
}