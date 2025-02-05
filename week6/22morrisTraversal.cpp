#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;  
    }
};

// Function for inorder traversal 
// using Morris Traversal
vector<int> inOrder(Node* root) {
    vector<int> result;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          
            // If no left child, visit this node 
            // and go right
            result.push_back(curr->data);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr &&
                                 prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                result.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return result;
}


int main() {
  
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //            / \  
    //           4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = inOrder(root);
  
     for (int data : result) {
        cout << data << " ";
    }
    
    return 0;
}
