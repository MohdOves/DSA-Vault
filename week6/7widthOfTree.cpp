// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//         int data;
//         node* left;
//         node* right;

//         node(int d){
//             this ->data  = d;
//             this ->left = NULL;
//             this -> right = NULL;
//         }
// };

// int height(node* root){
//         //base case
//         if(root == NULL){
//             return 0;
//         }

//         int left = height(root->left);
//         int right = height(root->right);

//         int ans = max(left,right) +1;
//         return ans;
//     }

// int MaxWidthOftree(node* root){

//     //base case
//     if(root == NULL){
//         return 0;
//     }

//     int right = MaxWidthOftree(root->left);
//     int left = MaxWidthOftree(root->right);
//     int both = height(root->left) + 1 + height(root->right);

//     int ans = max(right,max(left,both));
//     return ans;
// }


// int main(){

//     node* root = new node(1);
//     root->left = new node(2);
//     root->right = new node(3);
//     root->left->left = new node(4);
//     root->left->right = new node(5);
//     root->right->left = new node(6);
//     root->right->right = new node(7);

//     cout <<"max width of tree is : "<<MaxWidthOftree(root)<<endl;;

    
// }





//APPROACH 2

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




pair<int,int>diameterfast(node* root){

     //base case
    if(root == NULL){
        pair<int,int>p = make_pair(0,0);
        return p;
    }


    pair<int,int>left = diameterfast(root->left);
    pair<int,int>right = diameterfast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int>ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second) + 1;
    return ans;
}


int diameter(node* root){
    return diameterfast(root).first;
}


int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout <<"max width of tree is : "<<diameter(root)<<endl;;

    
}