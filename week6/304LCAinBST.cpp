#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* LCAinBST(Node* root,Node* P,Node* Q){
    
    //base case
    if(root == NULL){
        return NULL;
    }


    //recursin method

    if(root->data > P->data && root->data > Q->data){
        return LCAinBST(root->left,P,Q);
    }

    if(root->data < P->data && root->data < Q->data){
        return LCAinBST(root->right,P,Q);
    }
    return root;



    //iterative Method
    while(root != NULL){

        if(root->data > P->data && root->data > Q->data){
            root = root->left;
        }
        else if(root->data < P->data && root->data < Q->data){
            root = root->right;
        }
        else{
            return root;
        }
    }
}


int main(){

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Node* P = root->left;        // Node with data 3
    Node* Q = root->right->right; // Node with data 8

    Node* lca = LCAinBST(root, P, Q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << P->data << " and " << Q->data << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;

    
}