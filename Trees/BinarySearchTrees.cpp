//
//  main.cpp
//  Binary Search trees
//
//  Created by Salah on 1/1/23.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
    
};
class BinarySearchTree {
    Node* root;
public:
    BinarySearchTree(int val) {
        root = new Node(val);
    }
    BinarySearchTree() {
        root = NULL;
    }
    Node* getRoot() {
        return root;
    }
    void insertBST(int val) {
        if(!getRoot()) {
            root = new Node(val);
            return;
        }
        Node* currentNode = root;
        Node* parent = nullptr;
        while(currentNode) {
            parent = currentNode;
            if(val < currentNode -> data) {
                currentNode = currentNode -> left;
            }else{
                currentNode = currentNode -> right;
            }
        }
        if(val < parent -> data) {
            parent -> left = new Node(val);
        }else{
            parent -> right = new Node(val);
        }
    }
    void inOrderPrint(Node* currentNode) {
      if (currentNode != NULL) {
        inOrderPrint(currentNode -> left);
        cout << currentNode-> data << endl;
        inOrderPrint(currentNode -> right);
      }
    }
    Node* search(int val) {
        Node* currentNode = getRoot();
        while(currentNode != nullptr) {
            if(val < currentNode -> data) {
                currentNode = currentNode -> left;
            }else if(val > currentNode -> data) {
                currentNode = currentNode -> right;
            }else{
                break;
            }
        }
        return currentNode;
    }
    bool remove(Node* currentNode, int val) {
        // If Tree is empty
        if(!this->getRoot()) {
            return false;
        }
        Node* parent = nullptr;
        while(currentNode && currentNode -> data != val) {
            parent = currentNode;
            if(val < currentNode -> data) {
                currentNode = currentNode -> left;
            }else{
                currentNode = currentNode -> right;
            }
        }
        if(!currentNode) {
            return false;
        // Check if root/Leaf
        }else if(!currentNode -> left && !currentNode -> right) {
            if(root -> data == currentNode -> data) {
                delete root;
                root = NULL;
                return true;
            }else if(currentNode -> data < parent -> data) {
                delete parent -> left;
                parent -> left = NULL;
                return true;
            }else {
                delete parent -> right;
                parent -> right = NULL;
                return true;
            }
        //Check if w're not in the root and element has a left child only
        }else if(!currentNode -> right) {
            // Replace left child of node to be deleted with left or right of parent's
            if(root -> data == currentNode -> data) {
                delete root;
                root = currentNode -> left;
                return true;
            }else if(currentNode -> data < parent -> data) {
                delete parent -> left;
                parent -> left = currentNode -> left;
                return true;
            }else {
                delete parent -> right;
                parent -> right = currentNode -> left;
                return true;
            }
        }else if(!currentNode -> right ) {
            if(root -> data == currentNode -> data) {
                delete root;
                root = currentNode -> right;
                return true;
            }else if(currentNode -> data < parent -> data) {
                delete parent -> right;
                parent -> right = currentNode -> right;
                return true;
            }else {
                delete parent -> right;
                parent -> right = currentNode -> right;
                return true;
            }
            // Handled Everything that doesn't have two children
        }else {
            /* For the need that we're about to delete, we need to traverse the the entirety of the right subtree and check every left child for the smallest possible child. Swap the smallest possible child found with the node we want to delete and then  delete the node*/
            Node* leastNode = currentNode -> right;
            while(leastNode -> left) {
                leastNode = leastNode -> left;
            }
            int temporary = leastNode -> data;
            //Found the smallest, which should be a leaf, call it recursively
            remove(root, temporary);
            currentNode -> data = leastNode -> data;
            return true;
        }
    }
    void preorderTraversal(Node* currentNode) {
        if(!currentNode) {
            return;
        }
        cout << currentNode -> data << endl;
        preorderTraversal(currentNode -> left);
        preorderTraversal(currentNode -> right);
        // PreOrder is basically, Left right order
    }
    
    void postorderTraversal(Node* currentNode) {
        if(!currentNode) {
            return;
        }
        postorderTraversal(currentNode -> left);
        postorderTraversal(currentNode -> right);
        cout << currentNode -> data << endl;
        // Pattern is basically uhhhhhh
        // All the way left until we hit the leaves, then print, up the recursion stack once, then check right, all the way to root
        // Then repeat for right subtree
        // Then the recursion stack goes up to the root, in which case we print it last
    }
    void inorderTraversal(Node* currentNode) {
        if(!currentNode) {
            return;
        }
        inorderTraversal(currentNode -> left);
        // We're at the last;
        cout << currentNode -> data << endl;
        inorderTraversal(currentNode -> right);
        /* It basically prints stuff in order starting from left child, to the parent, to the right child and then the grandparents, etc*/
        
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    BinarySearchTree BST(6);
    BST.insertBST(4);
    BST.insertBST(9);
    BST.insertBST(5);
    BST.insertBST(2);
    BST.insertBST(8);
    BST.insertBST(12);
    cout << "InOrderTraversal" << endl;
    BST.inorderTraversal(BST.getRoot());
}
