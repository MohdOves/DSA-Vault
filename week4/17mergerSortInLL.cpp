#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor for insertion
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left,Node* right){

    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;

    //merger 2 sorted linked list
    while(left != NULL && right != NULL){
        if(left -> data < right->data){
                temp ->next = left;
                temp = left;
                left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp ->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;

}

Node* mergeSort(Node* head){

    //BASE CASE
    if(head == NULL || head->next == NULL){
        return head;
    }

    // break linked list into 2 healf after finding mid
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //recursive call to sort both half
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both left and right half
    Node* result = merge(left,right);

    return result;
}


void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    Node* node1 = new Node(5);
    Node* head = node1;

    Node* node2 = new Node(20);
    Node* node3 = new Node(10);
    Node* node4 = new Node(90);
    Node* node5 = new Node(40);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;


    print(head);

    mergeSort(head);
    print(head);
}