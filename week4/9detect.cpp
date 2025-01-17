#include<iostream>
#include<map>
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

void deleteNode(Node* &tail,int value){

    //empty list
    if(tail == NULL){
        cout <<"list is empty "<<endl;
    }
    else{
        //non empty

        //assuming that "value" is prent in the linked list

        Node* prev = tail;
        Node* curr = prev->next;

        while(curr ->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //1 node linked list
        if(curr == prev){
            tail = NULL;
        }


        //greater than 2 LL
        else if(tail == curr){
            tail = prev;
        }
        curr->next  = NULL;
        delete curr;
    }
}


bool detectLoop(Node* &head){

    if(head == NULL){
        return false;
    }

    map<Node*,bool>visited;

    Node* temp = head;

    while(temp != NULL){

        if(visited[temp] == true){
            cout <<"loop is cycle "<<endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
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

    // insertNode(tail,5,7);
    // print(tail);

    // insertNode(tail,7,9);
    // print(tail);

    // insertNode(tail,5,6);
    // print(tail);
    
    // insertNode(tail,9,10);
    // print(tail);

    // insertNode(tail,3,4);
    // print(tail);

    detectLoop(tail);
    
}