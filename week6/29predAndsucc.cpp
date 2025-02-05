#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

pair<int, int> predecessorOrSuccessor(Node* root, int key) {
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    // Find the key node
    while (temp != NULL && temp->data != key) {
        if (temp->data > key) {
            succ = temp->data;  // potential successor
            temp = temp->left;
        } else {
            pred = temp->data;  // potential predecessor
            temp = temp->right;
        }
    }

    // If key is not found
    if (temp == NULL) {
        return make_pair(-1, -1);
    }

    // Predecessor
    if (temp->left != NULL) {
        Node* leftTree = temp->left;
        while (leftTree->right != NULL) {
            leftTree = leftTree->right;
        }
        pred = leftTree->data;
    }

    // Successor
    if (temp->right != NULL) {
        Node* rightTree = temp->right;
        while (rightTree->left != NULL) {
            rightTree = rightTree->left;
        }
        succ = rightTree->data;
    }

    return make_pair(pred, succ);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int key = 3;
    pair<int, int> result = predecessorOrSuccessor(root, key);

    if (result.first == -1 && result.second == -1) {
        cout << "Key not found in the tree." << endl;
    } else {
        cout << "Predecessor: " << result.first << ", Successor: " << result.second << endl;
    }

    return 0;
}
