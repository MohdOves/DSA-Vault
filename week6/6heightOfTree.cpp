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

int height(node* root){
        //base case
        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left,right) +1;
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

    
    cout <<"height of tree is : "<<height(root)<<endl;
}