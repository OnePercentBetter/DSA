//
//  Node.hpp
//  Graphs
//
//  Created by Sal on 10/15/22.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>

class Node {
public:
    int data;
    Node* nextElement; //Pointer to next element
    Node();
};

#endif /* Node_hpp */
