
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

pair<int,int> solve(node* root){
    //base case
    if(root == NULL){
        pair<int,int>p = make_pair(0,0);
        return p;

    }

    pair<int,int>left = solve(root->left);
    pair<int,int>right= solve(root->right);

    pair<int,int>res;
    res.first= root->data + right.second;

    res.second = max(left.first,left.second) + max(right.first,right.second);

    return res;
}


int getMaxSum(node* root){
    pair<int,int>ans = solve(root);
    return max(ans.first,ans.second);
}


int main(){

    node* root = new node(10);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(1);
    root->right->left = new node(3);
    root->right->right = new node(4);

    cout << "Maximum sum of non-adjacent nodes: " << getMaxSum(root) << endl;
    
    return 0;
}