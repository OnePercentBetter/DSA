//
//  Stack.cpp
//  Binary Search trees
//
//  Created by C Ventin on 1/2/23.
//
#include <iostream>

// Stack Implementation Using Linked List Approach

 struct Node {
    int data;
    struct Node *next;
};
struct Node* top = NULL;

void push(int val) {
    Node * temp = new Node();
    temp -> data = val;
    temp -> next = top;
    top = temp;
}
bool isEmpty() {
    if(top == NULL) {
        return true;
    }else{
        return false;
    }
}

int top_Element() {
    if(!isEmpty()){
        return top->data;
    }else{
        return -1;
    }
}
void pop() {
    Node * temp;
    if(!isEmpty()){
        temp = top;
        top = top -> next;
        delete(temp);
    }else{
        std::cout<<"Empty" << std::endl;
    }
}

//Array Approach

class Stack {
private:
    int * stackArr;
    int capacity;
    int NumElement;
    
public:
    Stack(int size) {
        capacity = size;
        stackArr = new int[size];
        assert(stackArr != NULL);
        NumElement = 0;
    }
    
    bool isEmpty(){
        return NumElement == 0;
    }
    
    int getTop() {
        if(NumElement == 0) {
            return -1;
        }else {
            return stackArr[NumElement -1];
        }
        
        //Alternatively, we can sum it up
        // return (NumElements == 0 ? -1 : stackArr[NumElement -1];
    }
    
    int getSize() {
        return NumElement;
    }
    
    bool push(int value) {
        if(NumElement < capacity) {
            stackArr[NumElement] = value;
            NumElement++;
            return true;
        }else{
            return false;
        }
    }
    
    int pop() {
        if(NumElement == 0) {
            return -1;
        }else {
            return stackArr[--NumElement];
        }
    }
    
};

//Queue Implementation

class Node {
public:
    int data;
    Node* nextElement;
    Node* previousElement;
    
    Node(int data) {
        this->data = data;
        nextElement = nullptr;
        previousElement = nullptr;
        
    }
};

class DoublyLinkedList {
private:
    Node* tail;
    Node* head;
    
public:
    int size;
    DoublyLinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    ~DoublyLinkedList(){
        Node* current = head;
        Node* next;
        while(current) {
            next = current -> nextElement;
            delete(current);
            current = next;
        }
    }
    bool isEmpty(){
        return size == 0;
    }
    int getHead() {
        return head -> data;
    }
    int getTail(){
        return tail -> data;
    }
    
    int insertTail(int value) {
        Node* newNode = new Node(value);
        
        if(isEmpty()) {
            head = newNode;
            tail = newNode;
        }else{
            newNode -> previousElement = tail;
            tail -> nextElement = newNode;
            tail = newNode;
        }
        size++;
        
        return tail -> data;
    }
    
    bool deleteHead() {
        if(isEmpty()){
            return false;
        }
        Node* RemoveNode = head;
        if(size == 1) {
            head = nullptr;
            tail = nullptr;
        }else{
            head = head ->nextElement;
            head ->previousElement = nullptr;
            RemoveNode -> nextElement = nullptr;
        }
        delete RemoveNode;
        size--;
        return true;
    }
    
};

class Queue {
private:
    DoublyLinkedList items;
    
public:
    int isEmpty() {
        return items.size == 0;
    }
    
    int getFront(){
        if(!isEmpty()){
            return items.getHead();
        }else{
            return 0;
        }
    }
    int getSize() {
        return items.size;
    }
    
    int enqueue(int value) {
        return items.insertTail(value);
    }
    
    int dequeue() {
        return items.deleteHead();
    }
        
    std::string * findBin(int min) {
        std:: string * n = new std::string[min];
        // Size of the new string
        
        
        Queue s;
        std::string s1, s2;
        // Assume that we start off with 1
        s.enqueue(1);
        for(int i = 0; i < min; i++) {
            n[i] = std::to_string(s.dequeue());
            s1 = n[i] + "0";
            s2 = n[i] + "1";
            s.enqueue(stoi(s1));
            s.enqueue(stoi(s2));
        }
        return n;
    }
    
};
/*
#include <iostream>
int main() {
  struct foo_t {
    int x[100];
    int var1;
    int y[10];
    } foo;
  int var2;
  long i;
  int *p, *q;
  short int *s;
  long int *l;
  struct foo_t bar[50];

  for (i=0; i<100; i++) foo.x[i]=500+i;
  for (i=0; i<10; i++)  foo.y[i]=700+i;
  foo.var1 = 640;

  cout << sizeof(*s) << "\n";
  cout << sizeof(*p) << "\n";
  cout << sizeof(*l) << "\n";
  cout << sizeof(p) << "\n"; // MOD
  cout << sizeof(q) << "\n"; // MOD
  q = (int *) &foo;    cout << q << "\n"; // 500
  p=&(foo.x[5]);       cout << *p << "\n"; // 505
  // POINT 1
  q = (int *) &(foo.var1);   cout << q << "\n"; // var 2 = 1
  q = p+16;            cout << *q << "\n"; // 521
  i = ((long ) p) + 16;
  q = (int *) i;       cout << *q << "\n";
  s = (short *) i;     cout << *s << "\n";
  l = (long *) i;      cout << *l << "\n";
  q = p+96;            cout << *q << "\n";  // EXPLAIN
  q = p+98;            cout << *q << "\n";
  i = ((long) p) + 17;
  q = (int *) i;       cout << *q << "\n";
  q = p + 102;     cout << *q << "\n";
  q = (int *) (((long) p) + 408);  cout << *q << "\n";
  p = (int *) bar;
  *(p + 988) = 847; cout << bar[8].var1 << "\n";
    } */

