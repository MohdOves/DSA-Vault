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

//     ~Node(){
//         if(left){
//             delete left;
//         }
//         if(right){
//             delete right;
//         }
//     }
// };

// void inOrder(Node* root, vector<int>& in){
//     if(root == NULL){
//         return ;
//     }

//     inOrder(root->left,in);
//     in.push_back(root->data);
//     inOrder(root->right,in);
// }

// vector<int> mergeArrays(vector<int>& a,vector<int>& b){
//     vector<int>ans(a.size() + b.size());

//     int i = 0,j = 0;
//     int k = 0;

//     while(i < a.size() && b.size()){
//         if(a[i] < b[j]){
//             ans[k++] = a[i];
//             i++;
//         }
//         else{
//             ans[k++] = b[j];
//             j++;
//         }
//     }

//     while(i < a.size()){
//         ans[k++] = a[i];
//         i++;
//     }
//     while(j<b.size()){
//         ans[k++] = b[j];
//         j++;
//     }
//     return ans;
// }

// Node* inOrderToBST(int s,int e, vector<int>& in){
//     //base case
//     if(s>e){
//         return NULL;
//     }

//     int mid = (s+e)/2;
//     Node* root = new Node(in[mid]);
//     root->left = inOrderToBST(s,mid-1,in);
//     root->right = inOrderToBST(mid+1,e,in);

//     return root;
// }





// Node* mergeBst(Node* root1,Node* root2){

//     //step 1 : stored inorder
//     vector<int>bst1,bst2;
//     inOrder(root1,bst1);
//     inOrder(root2,bst2);

//     //step 2 : merger both sorted arrays
//     vector<int>mergeArray = mergeArrays(bst1,bst2);

//     //step 3 : use merged inorder arrays to build bst
//     int s = 0 ,e = mergeArray.size()-1;
//     return inOrderToBST(s,e,mergeArray);
// }

// int main(){

    
//     // Create two sample BSTs
//     Node* root1 = new Node(3);
//     root1->left = new Node(1);
//     root1->right = new Node(5);

//     Node* root2 = new Node(4);
//     root2->left = new Node(2);
//     root2->right = new Node(6);

//     // Merge the two BSTs
//     Node* mergedRoot = mergeBst(root1, root2);

//     // Print inorder traversal of merged BST to verify
//     vector<int> mergedInorder;
//     inOrder(mergedRoot, mergedInorder);
    
//     cout << "Inorder traversal of merged BST: ";
//     for(int val : mergedInorder) {
//         cout << val << " ";
//     }

//     // Clean up memory
//     delete root1;
//     delete root2;
//     delete mergedRoot;

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

      ~Node(){
        if(left){
            delete left;
        }
        if(right){
            delete right;
        }
    }

    
};


void convertIntoSortedLL(Node* root,Node* &head){
    //base case
    if(root == NULL){
        return;
    }

    convertIntoSortedLL(root->right,head);

    root->right = head;
    if(head != NULL)
        head->left = root;

    head = root;
    convertIntoSortedLL(root->left,head);
}


Node* mergeLinkedList(Node* head1,Node* head2){

    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){

            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{

            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
Node* sortedLLToBST(Node*& head, int n){
    //base case
    if(n <= 0 || head == NULL){
        return NULL;
    }

    Node* left = sortedLLToBST(head,n/2);

    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head,n-n/2-1);
    return root;
}


Node* mergeBst(Node* root1,Node* root2){

    //step 1: convert BST into Sorted DLL in place
    Node* head1 = NULL;
    convertIntoSortedLL(root1,head1);
    head1->left = NULL;

     Node* head2 = NULL;
    convertIntoSortedLL(root2,head2);
    head2->left = NULL;

    //step 2 : mergerd 2 sorted DLL
    Node* head = mergeLinkedList(head1,head2);

    //step 3 : convertSLL into BST
    return sortedLLToBST(head,countNodes(head));
}



void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}


int main(){

    
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    // Merge the two BSTs
    Node* mergedRoot = mergeBst(root1, root2);

    // Print inorder traversal of the merged BST to verify the result
    cout << "Inorder traversal of merged BST: ";
    printInOrder(mergedRoot);
    cout << endl;

    delete root1;
    delete root2;
    delete mergedRoot;
    

    return 0;


}


