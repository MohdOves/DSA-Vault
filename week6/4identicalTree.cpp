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


bool isIdentical(node* root1,node* root2){
    //base case
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL && root2 != NULL){
        return false;
    }

    if(root1 != NULL && root2 == NULL){
        return false;
    }

    bool left = isIdentical(root1->left ,root2->left);
    bool right = isIdentical(root1->right,root2->right);

    bool value = root1->data = root2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}



int main(){

    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);

    if (isIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }
 
}