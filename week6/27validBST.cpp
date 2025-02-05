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

bool isBST(Node* root,int min,int max){

    //base case
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
    
}


bool validBST(Node* root){

    return isBST(root,INT32_MIN,INT32_MAX);
}

int main(){

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(1);

    if(validBST(root)){
        cout<<"It is a valid BST "<<endl;
    }
    else{
        cout <<"Not a vslid BST"<<endl;
    }
}