#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data= data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrder(Node* root,int &count){
    //base case
    if(root == NULL){
        return ;
    }

    inOrder(root->left,count);

    //leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }

    
    inOrder(root->right,count);
}

int NoOfLeafNodes(Node* root){
    int count = 0;
    inOrder(root,count);
    return count;


}



int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Count leaf nodes
    int leafCount = NoOfLeafNodes(root);
    cout << "Number of leaf nodes: " << leafCount << endl;

    return 0;
}