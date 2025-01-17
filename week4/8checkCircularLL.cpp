#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data= d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout <<"memory is free for node with data"<<value<<endl;
    }
};

void insertNode(Node* &tail,int element,int d){

    
    //empty list
    if(tail == NULL){
        Node *newNode = new Node(d);
        tail = newNode;
        newNode ->next = newNode;
    }
    else{
        //not empty list
        //assuming that the element is present in the list

        Node* curr = tail;
        while(curr ->data != element){
            curr = curr->next;
        }

        //element found -> curr representing element wala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

    }
}

void print(Node* tail){

    Node* temp = tail;

    // empty list
    if(tail == NULL){
        cout <<"list is empty "<<endl;
        return ;
    }

    do{
    cout <<tail->data<<" ";
    tail = tail->next;
    }while(tail  != temp);

    cout <<endl;

}

bool isCircularList(Node* head){

    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp= temp->next;
    }

    if(temp == head){
        return true;
    }
    return false;

}

int main(){

    Node* tail = NULL;

    //empty list me insert krre hai
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    if(isCircularList(tail)){
        cout <<"linkedl list is circular"<<endl;
    }
    else{
        cout <<"linked list is not circular"<<endl;
    }

}