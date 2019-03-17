//
//  main.cpp
//  Stack
//
//  Created by Sailender Singh on 17/03/19.
//  Copyright © 2019 Sailender Singh. All rights reserved.
//

#include <iostream>

using namespace std;

class Stack {
    struct Node {
        int key;
        struct Node* next;
        Node() {
            key = 0;
            next = NULL;
        };
    };
    
    struct Node* root = NULL;
    
    struct Node* getNode(int key) {
        struct Node* node = new Node();
        node -> key = key;
        return node;
    }
    
public:
    
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        struct Node* toDelete = root;
        int key = toDelete->key;
        root = toDelete -> next;
        delete toDelete;
        return key;
    }
    
    void push(int key) {
        struct Node* node = getNode(key);
        node -> next = root;
        root = node;
    }
    
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        
        return root -> key;
    }
    
    bool isEmpty() {
        return root == NULL;
    }
    
    void printStack() {
        cout << endl;
        struct Node* localRoot = root;
        while (localRoot != NULL) {
            cout << localRoot->key <<" ";
            localRoot = localRoot -> next;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Stack *stack = new Stack();
    stack->push(10);
    stack->push(11);
    stack->push(12);
    stack->push(13);
    stack->push(14);
    stack->push(15);
    stack->push(16);
    stack->push(17);
    stack->printStack();

    cout << "poped element : "<< stack->pop() << endl;
    cout << "poped element : "<< stack->pop() << endl;
    cout << "poped element : "<< stack->pop() << endl;
    
    cout << "peek is called : "<< stack->peek() << endl;
    
    stack->printStack();
    
    
    stack -> pop();
    stack -> pop();
    stack -> pop();
    stack -> pop();
    stack -> pop();
    stack -> pop();
    stack -> pop();
    
    stack->printStack();
    
    
    cout << "isEmpty is called : "<< stack->isEmpty() << endl;
    
    return 0;
}
