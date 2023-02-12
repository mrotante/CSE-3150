#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;

queue<int> queue_push(char filepath[]) {
    queue<int> queue;
    ifstream file(filepath);
    string line;

    while(getline(file, line)) {
        stringstream lineStream(line);
        int val;
        
        while(lineStream >> val) {
            queue.push(val);
        }
    }
    return queue;
}

void queue_pop(queue<int> queue) {
    int sum = 0;
    while(!queue.empty()) {
        int front = queue.front();
        cout << front << " ";
        sum += front;
        queue.pop();
    }
    cout << endl;
    
    if(sum < 0) {
        throw invalid_argument("Queue sum cannot be negative");
    }
}

stack<int> stack_push(char filepath[]) {
    stack<int> stack;
    ifstream file(filepath);
    string line;

    while(getline(file, line)) {
        stringstream lineStream(line);
        int val;
        
        while(lineStream >> val) {
            stack.push(val);
        }
    }
    return stack;
}

void stack_pop(stack<int> stack) {
    int sum = 0;
    while(!stack.empty()) {
        int top = stack.top();
        cout << top << " ";
        sum += top;
        stack.pop();
    }
    cout << endl;
    
    if(sum < 0) {
        throw invalid_argument("Stack sum cannot be negative");
    }
}