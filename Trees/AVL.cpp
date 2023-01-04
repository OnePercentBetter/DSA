//
//  AVL.cpp
//  Binary Search trees
//
//  Created by Salah on 1/1/23.
//

#include <stdio.h>
// Implementing AVL trees
/*
 Criteria for BST:
    1. A key of any tree node is not less than the key in the left subtree
    2. A key of any tree node is greater than the key in the right subtree
 
 AVL is essentially self-balancing BST's */
struct node {
    int key;
    node* left;
    node* right;
    unsigned char height;
    node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};
// Height of node X
unsigned char height(node* p) {
    if(p) {
        return p -> height;
    }else{
        return 0;
    }
}
// Balance factor
int bfactor(node* p) {
    return height(p->right) - height(p -> left);
}
