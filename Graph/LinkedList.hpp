//
//  LinkedList.hpp
//  Graphs
//
//  Created by Sal on 10/15/22.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "Node.hpp"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    bool isEmpty();
    Node* getHead();
    bool printList();
    bool insertAtHead(int value);
    void insertAtTail(int value);
    bool search(int value);
    bool deleteAtHead(int value);
    bool Delete(int value);
};

#include <stdio.h>

#endif /* LinkedList_hpp */
