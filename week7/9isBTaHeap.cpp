#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;  
    }
};

int countNode(Node* root){
    //base case
    if(root == NULL){
        return 0;
    }

    int ans = 1+ countNode(root->left) + countNode(root->right);
    return ans;
}

bool isCBT(Node* root,int index,int count){
    if(root == NULL){
        return true;
    }

    if(index >= count){
        return false;
    }
    else{
        bool left = isCBT(root->left,2*index+1,count);
        bool right = isCBT(root->right,2*index+2,count);
        return (left && right);
    }

}

bool isMaxOrder(Node* root){
    //leaf node
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    //only left node
    if(root->right == NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return  (left && right && (root->data > root->left->data && root->data > root->right->data)) ;

    }
}

bool isHeap(Node* root){

    int index = 0;
    int totalCount = countNode(root);
    if( isCBT(root,index,totalCount) && isMaxOrder(root)){
        return true;
    }
    else{
        return false;
    }
}


int main() {
  
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    // Check if the binary tree is a max-heap
    if (isHeap(root)) {
        cout << "The binary tree is a max-heap." << endl;
    } else {
        cout << "The binary tree is not a max-heap." << endl;
    }

    return 0;
}
