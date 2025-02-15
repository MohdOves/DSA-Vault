#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* solve(vector<int>& preorder,int mini,int maxi,int &i){

    if(i >= preorder.size())
        return NULL;
    
    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder,mini,root->data,i);
    root->right = solve(preorder,root->data,maxi,i);

    return root;
}

Node* preOrderToBST(vector<int>& preorder){

    int mini = INT32_MIN;
    int maxi = INT32_MAX;

    int i = 0;
    return solve(preorder,mini,maxi,i);
}

void printInOrder(Node* root) {
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};  // Sample preorder input

    Node* root = preOrderToBST(preorder);

    cout << "In-order traversal of the constructed BST: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
