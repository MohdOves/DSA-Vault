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

int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node* findMiddle(Node* head){
    int len = getLength(head);
    int ans = (len/2);

    Node* temp = head;
    int cnt = 0;
    while(cnt < ans){
        temp = temp->next;
        cnt++;
    }
    return temp;
    
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {

    Node* node1 = new Node(10);
    Node* head = node1;

    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    head->next = node2;
    node2->next = node3;

    Node* node4 = new Node(40);
    node3->next = node4;

    print(head);

    Node* middle = findMiddle(head);
    cout <<"middle node: "<<middle->data<<endl;
   
}