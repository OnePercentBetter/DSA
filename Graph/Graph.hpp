//
//  Graph.hpp
//  Graphs
//
//  Created by Sal on 10/15/22.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "LinkedList.cpp"

class Graph {
private:
    int vertices;
    LinkedList* array;

public:
    Graph(int v);

    void addEdge(int source, int destination);

    void printGraph();

    LinkedList* getArray();

    int getVertices();
};


#endif /* Graph_hpp */
