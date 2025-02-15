#include <iostream>
#include <vector>
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

void inOrder(Node* root, vector<int> &in) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

Node* flatten(Node* root) {
    vector<int> inOrderVal;
    // Store inorder traversal (sorted values)
    inOrder(root, inOrderVal);
    int n = inOrderVal.size();

    if (n == 0) return NULL;  // Edge case: if the tree is empty

    Node* newRoot = new Node(inOrderVal[0]);
    Node* curr = newRoot;

    // Flatten the tree
    for (int i = 1; i < n; i++) {  // Start from 1 to avoid duplicating the first node
        Node* temp = new Node(inOrderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;  // Set the last node's right to NULL

    return newRoot;  // Return the head of the flattened tree
}

void printFlattenedTree(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);  // Changed this node to 8 instead of 1 for a proper BST

    Node* flattenedRoot = flatten(root);
    printFlattenedTree(flattenedRoot);

    return 0;
}
