//
//  Graph.cpp
//  Graphs
//
//  Created by Sal on 10/15/22.
//
#include "Graph.hpp"

using namespace std;

Graph::Graph(int v)
{
    array = new LinkedList[v];
    vertices = v;
}

void Graph::addEdge(int source, int destination)
{
    if (source < vertices && destination < vertices){
    array[source].insertAtHead(destination);
    array[destination].insertAtHead(source);
}
}

void Graph::printGraph()
{
    cout << "Adjacency List of Undirected Graph" << endl;
    Node* temp;
    for (int i = 0; i < vertices; i++) {
        cout << "|" << i << "| => ";
        temp = (array[i]).getHead();

        while (temp != NULL) {
            cout << "[" << temp->data << "] -> ";
            temp = temp->nextElement;
        }
        cout << "NULL" << endl;
    }
}

LinkedList* Graph::getArray()
{
    // Where Array holds all Adjacency Lists such that each represents a vertex and all adjacent vertices to it
    
    return array;
}

int Graph::getVertices()
{
    return vertices;
}
int w = 100;
int h = 200;
int d = 50;


int height = 512;
int width = 256;

int starting_Point = 512 * (256 - h) * 4;

int centered = (512 - w) / 2;

arr[524288] // FrameBuffer, the bitmap
int last_pixel = 524288;

for(int i = 4, i < last_pixel; i += 4) {
    if(i == starting_point)
}
