// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int d){
//         this->data = d;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };



// bool searchBST(Node* root,int x){

//     //base case
//     if(root == NULL){
//         return false;
//     }

//     if(root->data == x){
//         return true;
//     }

//     if(root->data > x){
//         //left part me
//        return searchBST(root->left,x); 
//     }

//     if(root->data < x){
//         //right part me
//         return searchBST(root->right,x);
//     }


// }


// int main(){

//     Node* root = new Node(5);
//     root->left = new Node(3);
//     root->right = new Node(7);
//     root->left->left = new Node(2);
//     root->left->right = new Node(4);
//     root->right->left = new Node(6);
//     root->right->right = new Node(8);

//     // Search for a specific value in the BST
//     int x;
//     cout << "Enter value to search in BST: ";
//     cin >> x;

//     if (searchBST(root, x)) {
//         cout << "Value " << x << " found in the BST." << endl;
//     } else {
//         cout << "Value " << x << " not found in the BST." << endl;
//     }

//     return 0;

// }



//APPROACH 2

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


bool searchInBST(Node* root,int x){

    Node* temp =  root;

    while(temp != NULL){

        if(root->data == x){
            return true;
        }
        if(root->data > x ){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

Node* minValue(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}


Node* maxValue(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}


int main(){

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    
    int x;
    cout << "Enter value to search in BST: ";
    cin >> x;

    if (searchInBST(root, x)) {
        cout << "Value " << x << " found in the BST." << endl;
    } else {
        cout << "Value " << x << " not found in the BST." << endl;
    }
    

    cout <<"MIn value is : "<<minValue(root)->data<<endl;

    cout <<"Max value is : "<<maxValue(root)->data<<endl;
    
    return 0;

}