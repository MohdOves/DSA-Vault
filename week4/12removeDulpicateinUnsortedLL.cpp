#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


Node* removeDuplicate(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr;

        while(temp->next != NULL){
            if(curr->data == temp->next->data){
                Node* nodeTODelete = temp->next;
                 temp->next = temp->next->next;
                delete(nodeTODelete);

               
            }
            else{//not eqaul
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
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

     Node* node1 = new Node(10);
    Node* head = node1;

    Node* node2 = new Node(40);
    Node* node3 = new Node(20);
    Node* node4 = new Node(40);
    Node* node5 = new Node(50);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    print(head);

    removeDuplicate(head);
    print(head);
}