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

Node* kReverse(Node* head,int k){

    //base case
    if(head == NULL){
        return NULL;
    }

    //step 1; reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int count = 0;

    while(curr != NULL && count <k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step 2 : recursion dekh lega aage ka
    if(next != NULL){
        head->next = kReverse(next,k);
    }

    //step 3: return head of reverse LL
    return prev;

}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout <<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;

    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    head->next = node2;
    node2->next = node3;

    print(head);

    head = kReverse(head,2);
    print(head);



}