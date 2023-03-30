#ifndef __SMART_POINTERS_LINKED_LIST__
#define __SMART_POINTERS_LINKED_LIST__

using namespace std;

struct List {
    struct Node {
        int data;
        unique_ptr<Node> next;
        Node(int data) : data(data), next(nullptr) {}
    };

    unique_ptr<Node> head;

    ~List() {
        head.reset();
    }

    void push(int data) {
        unique_ptr<Node> node(new Node(data));
        node->next = move(head);
        head = move(node);
    }
};

#endif