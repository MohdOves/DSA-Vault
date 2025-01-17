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

Node* uniqueSortedList(Node* head) {

    //empoty list
    if(head == NULL){
        return NULL;
    }

    //non empty list
    Node* curr = head;

    while(curr != NULL){
        if((curr->next != NULL) && curr ->data == curr->next->data  ){

            Node* next_next = curr->next->next;

            Node* nodeTODelete = curr->next;
            delete(nodeTODelete);

            curr->next = next_next;
        }
        else{//not eqaul
            curr = curr->next;
        }

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

    Node* node2 = new Node(20);
    Node* node3 = new Node(20);
    Node* node4 = new Node(30);
    Node* node5 = new Node(40);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    print(head);
    cout <<endl;

    head = uniqueSortedList(head);
    print(head);


    

}