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


Node* reverseLinkedList(Node *head){

    //if LL is empty or 1 node
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }return prev;
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