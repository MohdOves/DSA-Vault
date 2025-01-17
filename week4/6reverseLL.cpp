#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(Node* &head, Node* curr,Node* prev){

    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev;
}


Node* reverseLinkedList(Node *head){

    Node* curr = head;
    Node* prev = NULL;
    reverse(head,curr,prev);
    return head;
}



int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    head->next = node2;
    node2->next = node3;

    cout <<"linked list : "<<endl;
    print(head);

    cout <<"reverse linked list : "<<endl;

    head = reverseLinkedList(head);
    print(head);

}