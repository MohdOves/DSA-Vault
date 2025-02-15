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

Node* inOrderToBST(int s,int e, vector<int>& in){
    //base case
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = inOrderToBST(s,mid-1,in);
    root->right = inOrderToBST(mid+1,e,in);

    return root;
}

Node* balancedBST(Node* root){
    vector<int> inOrderVal;
    // Store inorder traversal (sorted values)
    inOrder(root, inOrderVal);
    int n = inOrderVal.size();

    return inOrderToBST(0,n-1,inOrderVal);

}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);  // Changed this node to 8 instead of 1 for a proper BST


    Node* balancedRoot = balancedBST(root);
    cout << "In-order traversal of the balanced BST: ";
    printInOrder(balancedRoot);
    cout << endl;

    return 0;
    
}
