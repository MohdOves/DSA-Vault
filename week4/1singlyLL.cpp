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

    //destructor for delteion
    ~Node(){
        int value = this->data;

        //memry free 
        if(this->next !=NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data "<<value <<endl;
    }
};


void insertAtHead(Node* &head,int d){

    //new node create
    Node* temp = new Node(d);
    temp ->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int d){

    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}



void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp->next;
    }
    cout <<endl;
}

void insertAtPosition(Node* tail,Node* &head,int position,int d){

    //insert at start
    while(position == 1){
        insertAtHead(head,d);
        return ;
    }

    
    // insert at any position
    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;


    //insert at last
    while(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

}

void deleteNode(int position,Node* &head){

    //deletion first node
    if( position ==1){
        Node* temp = head;
        head = head->next;

        //memory free start node
        temp->next = NULL;
        delete temp;
    }
    else{

        //deleting any middle or last node
        Node* curr = head;
        Node*prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev ->next = curr->next;
        curr->next = NULL;
        delete curr;  
    }
}



int main(){

    //create a new node
    Node* node1 = new Node(10);
    // cout << node1->data<<endl;
    // cout <<node1->next<<endl;


    //head pointed to node1
    Node* head = node1;
    Node*tail = node1;
    print (head);

    insertAtHead(head,12);
    insertAtHead(head,15);
    print(head);


    // insertAtTail(head,20);
    // print(tail);

    // insertAtTail(head,30);
    // print(tail);

    insertAtPosition(tail,head,3,22);
    print(head);

    cout <<"head"<<head->data<<endl;
    cout <<"tail"<<tail->data<<endl;

    deleteNode(2,head);
    print(head);
    
}