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


// bool isBalanced(node* root){
//     //base case
//     if(root == NULL){
//         return true;
//     }

//     bool left = isBalanced(root->left);
//     bool right = isBalanced(root->right);

//     bool difference = abs(height(root->left) - height(root->right) ) <=1;

//     if(left && right && difference){
//         return 1;
//     }
//     else{
//         return false;
//     }
// }


// int main(){

//     node* root = new node(1);
//     root->left = new node(2);
//     root->right = new node(3);
//     root->left->left = new node(4);
//     root->left->right = new node(5);
//     root->right->left = new node(6);
//     root->right->right = new node(7);

//     if (isBalanced(root)) {
//         cout << "The tree is balanced." << endl;
//     } else {
//         cout << "The tree is not balanced." << endl;
//     }
 
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



pair<bool,int> isBalancedFast(node* root){
    //base case
    if(root == NULL){
        pair<bool,int>p = make_pair(true,0);
        return p;
    }

    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool difference = abs(left.second - right.second ) <=1;

    pair<bool,int>ans;
    ans.second = max(left.second,right.second) +1;

    if(leftAns && rightAns && difference){
        ans.first = 1;
    }
    else{
        ans.first = false;
    }
    return ans;

}


bool isBalanced(node* root){
    
    return isBalancedFast(root).first;
}


int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
 
}