// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//         int data;
//         node* left;
//         node* right;

//         node(int d){
//             this ->data  = d;
//             this ->left = NULL;
//             this -> right = NULL;
//         }
// };

// node* solve(node* root, int &k, int node){
//     // Base case
//     if(root == NULL){
//         return NULL;
//     }

//     // Check if the current node is the target node
//     if(root->data == node){
//         return root;
//     }

//     // Recur for left and right subtrees
//     node* leftAns = solve(root->left, k, node);
//     node* rightAns = solve(root->right, k, node);

//     if(leftAns != NULL && rightAns == NULL){
//         k--;
//         if(k <= 0){
//             k = INT32_MAX; // Mark that ancestor is found
//             return root;
//         }
//         return leftAns;
//     }

//     if(leftAns == NULL && rightAns != NULL){
//         k--;
//         if(k <= 0){
//             k = INT32_MAX; // Mark that ancestor is found
//             return root;
//         }
//         return rightAns;
//     }

//     return NULL;
// }


// int kthAncestor(node* root, int k, int node){
//     node* ans = solve(root, k, node);

//     // Check if ancestor exists
//     if(ans == NULL || ans->data == node)
//         return -1;
//     else
//         return ans->data;
// }


// int main(){
//     node* root = new node(1);
//     root->left = new node(2);
//     root->right = new node(3);
//     root->left->left = new node(4);
//     root->left->right = new node(5);
//     root->right->right = new node(6);

//     int k = 2;
//     int targetNode = 5;
//     int ancestor = kthAncestor(root, k, targetNode);

//     if (ancestor != -1) {
//         cout << "The " << k << "th ancestor of node " << targetNode << " is " << ancestor << endl;
//     } else {
//         cout << "The " << k << "th ancestor of node " << targetNode << " does not exist." << endl;
//     }

//     return 0;
// }


//APPROACH 2

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Recursive function to find path to the target node
bool findPath(Node* root, vector<int>& path, int target) {
    if (root == NULL) {
        return false;
    }

    // Add the current node to the path
    path.push_back(root->data);

    // If the target node is found, return true
    if (root->data == target) {
        return true;
    }

    // Recursively check left and right subtrees
    if (findPath(root->left, path, target) || findPath(root->right, path, target)) {
        return true;
    }

    // If the target is not in either subtree, backtrack by removing the current node
    path.pop_back();
    return false;
}

int kthAncestor(Node* root, int k, int target) {
    vector<int> path;

    // Find path from root to target node
    if (!findPath(root, path, target)) {
        // If target node is not present in the tree
        return -1;
    }

    // Check if kth ancestor is within the path length
    int pathSize = path.size();
    if (pathSize <= k) {
        return -1; // Kth ancestor does not exist
    }

    // Return the Kth ancestor
    return path[pathSize - k - 1];
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int k = 2;
    int target = 5;
    int ancestor = kthAncestor(root, k, target);

    if (ancestor != -1) {
        cout << "The " << k << "th ancestor of node " << target << " is " << ancestor << endl;
    } else {
        cout << "The " << k << "th ancestor of node " << target << " does not exist." << endl;
    }

    return 0;
}
