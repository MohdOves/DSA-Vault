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


node* lca(node* root,int n1, int n2){
    //base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* leftAns = lca(root->left,n1,n2);
    node* rightAns = lca(root->right,n1,n2);

    if(leftAns != NULL && rightAns != NULL)
        return root;
    
    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;
    
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    
    else
        return NULL;
    

}


int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    int n1 = 4, n2 = 5;
    node* ancestor = lca(root, n1, n2);
    
    if (ancestor != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ancestor->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;



    return 0;
}