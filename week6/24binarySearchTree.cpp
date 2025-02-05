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

void inOrder(Node* root){
    //base case
    if(root == NULL){
        return ;
    }

    inOrder(root->left);
    cout <<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    //base case
    if(root == NULL){
        return ;
    }

    cout <<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    //base case
    if(root == NULL){
        return ;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout <<root->data<<" ";
}


void levelOderTraversal(Node* root){

    queue<Node* >q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        
        q.pop();

        if(temp == NULL){ // purana level complete traverse ho couka hai
            cout <<endl;
            if(!q.empty()){
                q.push(NULL);
            }  
        }
        else{
            cout <<temp ->data <<" ";

            if(temp ->left){
            q.push(temp->left);
            }

            if(temp ->right){
            q.push(temp->right);
            }
        }
    }
}



Node*  insertIntoBST(Node* root, int d){

    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        //right part me insert karna h
        root->right = insertIntoBST(root->right,d);
    }
    else{
        //left part me insert karna h
        root->left = insertIntoBST(root->left,d);
    }
}


Node*  takeInput(Node* root){

    int data;
    cin>>data;

    while(data != -1){
        root =  insertIntoBST(root,data);
        cin>>data;
    }
    return root;
}




int main(){

    Node* root = NULL;

    cout << "Enter data to create BST : "<<endl;
    root = takeInput(root);

    cout <<"Printing the BST : "<<endl;
    levelOderTraversal(root);

    cout <<endl;

    cout <<"Printing inorder traversal : "<<endl;
    inOrder(root);

    cout <<endl;

    cout <<"Printing preorder traversal : "<<endl;
    preOrder(root);

    cout <<endl;

    cout <<"Printing postorder traversal : "<<endl;
    postOrder(root);

    cout <<endl;


}