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

vector<int> zigZagTraversal(node* root){

    vector<int>result;

    if(root == NULL){
        return result;
    }

    queue<node*>q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){

        int size = q.size();
        vector<int>ans(size);

        //level process
        for(int i = 0;i<size;i++){
            node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size-i-1;
            ans[index] = frontNode->data;

            if(frontNode->left)
                q.push(frontNode->left);
            

            if(frontNode->right)
                q.push(frontNode->right);
        }

        leftToRight = !leftToRight;


        for(auto i: ans){
            result.push_back(i);
        }

    }
    return result;
}




int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> traversal = zigZagTraversal(root);

    // Printing the zigzag order traversal
    cout << "ZigZag Traversal: ";
    for(int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
    
    
}