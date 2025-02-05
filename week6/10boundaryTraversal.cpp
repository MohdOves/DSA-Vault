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

void traverseLeft(node* root, vector<int> &ans){

    //base case
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return ;
    }

    ans.push_back(root->data);

    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}



void traverseLeaf(node* root , vector<int>& ans){

    //base case
    if(root == NULL){
        return ;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}


void traverseRight(node* root,vector<int>& ans){
    //base case
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->right,ans);
    }

    //wapas aagaye
    ans.push_back(root->data);


}




vector<int> boundary(node* root){

    vector<int>ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);

    //left part print/store
    traverseLeft(root->left,ans);

    //traverse leaf node
    //left sub tree
    traverseLeaf(root->left,ans);
    //right sub tree
    traverseLeaf(root->right,ans);

    //traverse right part
    traverseRight(root->right,ans);

    return ans;
}




int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> boundaryTraversal = boundary(root);

    // Printing the boundary traversal
    cout << "Boundary Traversal: ";
    for (int val : boundaryTraversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
    
    
}