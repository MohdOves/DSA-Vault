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

pair<bool,int> isSumtreeFast(node* root){

    //base case
    if(root == NULL){
        pair<bool,int>p = make_pair(true,0);
        return p;
    }

    //leaf node
    if(root->left ==NULL && root->right == NULL){
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumtreeFast(root->left);
    pair<bool,int> rightAns = isSumtreeFast(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumtree = rightAns.first;

    int leftSum = leftAns.first;
    int rightSum = rightAns.second;

    bool condn  = root->data == leftSum + rightSum;
    
    pair<bool,int> ans;

    if(isLeftSumTree && isRightSumtree && condn){
        ans.first = true;
        ans.second = root->data + leftSum + rightSum ;
    }
    else{
        ans.first = false;
    }
    return ans;
    }


bool isSumTree(node* root){
    return isSumtreeFast(root).first;
}



int main(){

    


    node* root1 = new node(26);
    root1->left = new node(10);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(6);
    root1->right->right = new node(3);

    if (isSumTree(root1)) {
        cout << "The tree is a sum tree." << endl;
    } else {
        cout << "The tree is not a sum tree." << endl;
    }


 
}