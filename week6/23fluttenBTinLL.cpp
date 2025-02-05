#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this ->data  = d;
            this ->left = NULL;
            this -> right = NULL;
        }
};

void flatten(node* root){

    node* curr = root;
    while(curr != NULL){
        
        if(curr->left){

            node* pred = curr->left;
            while(pred->right){
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;      
        }
        curr = curr->right;
    } 
}

void printFlattenedTree(node* root) {
    node* curr = root;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main() {
  
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(6);

    flatten(root);
    
    // Print flattened tree
    cout << "Flattened tree: ";
    printFlattenedTree(root);
    cout << endl;

    return 0;


}