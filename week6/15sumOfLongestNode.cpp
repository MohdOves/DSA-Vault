#include<iostream>
// #include<bits/stdc++.h>
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


void solve(node*root,int sum,int &maxSum,int len, int& maxLen){
    //base case
    if(root == NULL){

        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum,maxSum);
        }
        return ;
    }

    sum = sum + root->data;

    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->left,sum,maxSum,len+1,maxLen);

}


int sumOfLongRootToLeafPath(node* root){
    int len = 0;
    int maxLen = 0 ;

    int sum = 0;
    int maxSum = INT32_MIN;

    solve(root,sum,maxSum,len,maxSum);

    return maxSum;
}


int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    
    cout << "Sum of the longest root-to-leaf path is: " << sumOfLongRootToLeafPath(root) << endl;

    return 0;
    
    
}