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

void solve(node* root, vector<int>& ans, int level){
    //base case
    if(root == NULL){
        return ;
    }

    //we entered into new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);

}

vector<int> leftView(node* root){

    vector<int>ans;
    solve(root,ans,0);
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

    vector<int> result = leftView(root);

    // Print the result
    cout << "Left view of the binary tree is: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;

    
}