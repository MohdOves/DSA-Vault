



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


Node* minValue(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}


Node* deleteFromBST(Node* root,int val){
    //base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){

        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left !=NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }

    else{
        root->right = deleteFromBST(root->right,val);
        return root;
    }
}


int main(){

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);


    cout <<"Printing the BST : "<<endl;
    levelOderTraversal(root);

    root = deleteFromBST(root,6);

    cout <<"Printing the BST : "<<endl;
    levelOderTraversal(root);

    

}