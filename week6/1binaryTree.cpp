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

node* buildTree(node* root){

    cout <<"Enter the Data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    
    if(data == -1){
        return NULL;
    }

    cout <<"Enter Data for Insert at Left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout <<"Enter Data for Insert at Right of  "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}


void levelOderTraversal(node* root){

    queue<node* >q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        
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


void inOrder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    inOrder(root->left);
    cout <<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    cout <<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout <<root->data<<" ";
}






int main(){
    node* root = NULL;

    // // create a tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order 
    cout <<"printing the level oder traversal output  "<<endl;
    levelOderTraversal(root);
    

    cout <<"inoreder traversal is : ";
    inOrder(root);
    cout <<endl;

    cout <<"preOrder traversal is : ";
    preOrder(root);

    cout <<endl;

    cout <<"postOder traversal is : ";
    postOrder(root);


}
