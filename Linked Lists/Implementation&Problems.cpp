//
//  main.cpp
//  Linked List
//
//  Created by Sal on 9/09/22.
//

#include <iostream>

class Node {
public:
    int data;
    Node * nextElement;
    
    Node() {
        nextElement = nullptr;
    }
};

class LinkedList {
    Node * head;
    
    LinkedList() {
        head = nullptr;
    }
    
    bool isEmpty() {
        if(head == nullptr) {
            return true;
        }else {
            return false;
        }
    }
    
    std::string elements() { // this function will return all values of linked List
        
      std::string elementsList = "";
      Node * start = head;

      while (start != nullptr) {
        elementsList += std::to_string(start->data);
        elementsList += "->";
        start = start->nextElement;
      }
      elementsList += "null";
      return elementsList;
    }
    
    
    Node * getHead() {
        return head;
    }
    
    void insertAtTail(int value) {
      // Enter your code here
      if(head == nullptr) {
        Node * newNode = new Node();
        newNode -> data = value;
        newNode -> nextElement = head;
        head = newNode;
      }else {
        Node * newNode = new Node();
        newNode -> data = value;
        newNode -> nextElement = nullptr;
        Node * temp = head;
        while(temp != nullptr) {
          if(temp -> nextElement == nullptr) {
            temp -> nextElement = newNode;
            break;
          }
          temp = temp -> nextElement;
        }
      }
    }
    
    bool search(int value){
      Node * temp = head;
      while(temp != nullptr){
        if(temp->data == value){
          return true;
        }
        temp = temp->nextElement;
      }
      return false;
    }
    
    bool deleteAtHead() {
        if(isEmpty()) {
            return false;
        }
        Node * current = head;
        head = head -> nextElement;
        
        delete current;
        return true;
    }
    
    bool Delete(int value) {
        
      if(isEmpty()) {
        return false;
      }
        Node * current = head;
        Node * previous = nullptr;

        if(current -> data == value) {
          return deleteAtHead();
        }
        
        previous = current;
        current = current -> nextElement;

        while(current != nullptr) {
          if(current -> data == value) {
            previous -> nextElement = current -> nextElement;
            delete current;
            return true;
          }

          previous = previous -> nextElement;
          current = current -> nextElement;
        }

      return false;
    }
    
    int length() {
        if(head == nullptr){
                return 0;
            }
        
        int counter = 0;
        Node * temp = head;
        while(temp != nullptr){
            counter++;
            temp = temp -> nextElement;
        }
        return counter;
    }
    
    std::string reverse() {
      Node * previous = nullptr;
      Node * current = head;
      Node * temp = nullptr;
      while(current != nullptr) {
        temp = current->nextElement;
        current -> nextElement = previous;
        previous = current;
        current = temp;
      }
      head = previous;
      return elements();
    }
    
    std::string removeDuplicates() {
        struct Node * start, * nextStart, * dup;
        start = head;

        while(start != nullptr && start -> nextElement != nullptr) {
          nextStart = start;

          while(nextStart->nextElement != nullptr) {
            if(nextStart -> nextElement -> data == start -> data) {
              dup = nextStart -> nextElement;
              nextStart -> nextElement = nextStart -> nextElement -> nextElement;
              delete(dup);
            }else {
              nextStart = nextStart ->nextElement;
            }
          }
          start = start -> nextElement;
        }
      return elements();
    }
    
    std::string Union(LinkedList list1, LinkedList list2) {
        // Write your code here
        if(list1.isEmpty()) {
          return list2.elements();
        }else if(list2.isEmpty()) {
          return list1.elements();
        }

        struct Node * start = list1.head, * next = list2.head;
        bool found = false;

        while(start != nullptr && next != nullptr){
          list1.insertAtTail(next -> data);
          next = next -> nextElement;
        }
      return list1.removeDuplicates();// removing duplicates from list and return list
    }


    std::string Intersection(LinkedList list1,LinkedList list2) {
      LinkedList list3;
        // Write your code here
      struct Node * l1 = list1.head, * l2 = list2.head;
      
      while(l1 != nullptr){
        while(l2 != nullptr) {
          if(l1 ->data == l2 -> data) {
            list3.insertAtHead(l1->data);
          }
          l2 = l2 -> nextElement;
        }
        l2 = list2.head;
        l1 = l1 -> nextElement;
      }
      list3.printList();
      return list3.elements();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
