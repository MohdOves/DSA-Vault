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

void inOrder(Node* root,vector<int> &in){
    if(root == NULL){
        return;
    }

    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);
}

bool twoSumInBST(Node* root,int target){

    vector<int> inOrderVal;
    inOrder(root,inOrderVal);

    //use two pointer approach to find pair exist
    int i = 0,j = inOrderVal.size()-1;

    while(i<j){
        int sum = inOrderVal[i] + inOrderVal[j];

        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(1);

    int target = 67;

    if(twoSumInBST(root,target)){
        cout << "The sum is available"<<endl;
    }
    else{
        cout <<"Not available"<<endl;
    }

    
    
}