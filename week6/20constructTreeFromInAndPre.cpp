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

int findPosition(int* in,int element,int n){

    for(int i = 0;i<n;i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}


node* solve(int* in,int* pre,int &index,int inorderStart,int inorderEnd,int n){

    //base case
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }

    //create a root node for element
    int element = pre[index++];
    node* root = new node(element);

    //find element index in inorder
    int position = findPosition(in,element,n);

    //recursive call
    root->left = solve(in,pre,index,inorderStart,position-1,n);
    root->right = solve(in,pre,index,position+1,inorderEnd,n);

    return root;

}

node* buildTree(int* in,int* pre,int n){

    int preoderIndex = 0;
    node* ans =  solve(in,pre,preoderIndex,0,n-1,n);
    return ans;
}

void printPostorder(node* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    int in[] = {3,1,4,0,5,2};  // Inorder traversal
    int pre[] = {0,1,3,4,2,5}; // Preorder traversal
    int n = sizeof(in) / sizeof(in[0]);

    node* root = buildTree(in, pre, n);

    // Print the constructed tree's postorder traversal
    cout << "Postorder traversal of constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}