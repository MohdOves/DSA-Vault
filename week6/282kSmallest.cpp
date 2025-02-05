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

int solve(Node* root,int& i,int k){
    //base case
    if(root == NULL){
        return -1;
    }
    //Left
    int left = solve(root->left ,i,k);

    if(left != -1){
        return left;
    }

    //N
    i++;
    if(i == k){
        return root->data;
    }

    //Right
    return solve(root->right,i,k);
}

int kthSmallest(Node* root,int k){
    int i = 0;
    int ans = solve(root,i,k);
    return ans;
}

int main(){

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int k = 3;
    int result = kthSmallest(root, k);
    if (result != -1) {
        cout << k << "-th smallest element is: " << result << endl;
    } else {
        cout << "The tree has fewer than " << k << " elements." << endl;
    }

    return 0;

    
}