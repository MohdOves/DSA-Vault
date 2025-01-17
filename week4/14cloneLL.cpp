// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;
//     Node* random;

//     //constructor
//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//         this->random = NULL;
//     }
// };

// void insertAtTail(Node* &head,Node* &tail,int d){
//     Node* newNode = new Node(d);
//     if(head == NULL){
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     else{
//         tail->next = newNode;
//         tail = newNode;
//     }
// }

// Node* copyList(Node* head){

//     //step1 create a clone list
//     Node* cloneHead = NULL;
//     Node* cloneTail = NULL;

//     Node* temp = head;

//     while(temp != NULL){
//         insertAtTail(cloneHead,cloneTail,temp->data);
//         temp= temp->next;
//     }

//     //step2- create a map
//     unordered_map<Node*,Node*> oldToNewNode;

//     Node* originalNode = head;
//     Node* cloneNode = cloneHead;
//     while(originalNode != NULL && cloneNode != NULL){

//         oldToNewNode[originalNode] = cloneNode;
//         originalNode = originalNode->next;
//         cloneNode = cloneNode->next;
//     }

//     originalNode = head;
//     cloneNode = cloneHead;

//     while(originalNode != NULL){
//         cloneNode->random = oldToNewNode[originalNode->random];
//         originalNode = originalNode->next;
//         cloneNode = cloneNode->next;
//     }
//     return cloneHead;
// }

// void printList(Node* head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout << "Data: " << temp->data << ", Random: " 
//              << (temp->random ? temp->random->data : -1) << endl;
//         temp = temp->next;
//     }
// }

// int main(){

//     Node* head = new Node(1);
//     Node* second = new Node(2);
//     Node* third = new Node(3);

//     head->next = second;
//     second->next = third;

//     // Setting up random pointers
//     head->random = third;
//     second->random = head;
//     third->random = second;

//     cout << "Original list:\n";
//     printList(head);

//     // Clone the list
//     Node* clonedList = copyList(head);

//     cout << "\nCloned list:\n";
//     printList(clonedList);

//     return 0;
// }



//aprroach 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int d){
    Node* newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

Node* copyList(Node* head){

    //step1- create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp !=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }

    //step2- cloneNode add in between original node

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode= next;
    }

    //step3 - random pointer copy

    temp = head;
    while(temp != NULL){
        if(temp->next != NULL){

            temp->next->random = temp->random ? temp->random->next : temp->random;
        }

        temp = temp->next->next;
    }

    //step4 - revert changes does in step2

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        originalNode->next = cloneNode->next;
        originalNode= originalNode->next;

        if(originalNode != NULL){
            cloneNode->next = originalNode->next;
        }
        cloneNode= cloneNode->next;
    }

    //step5 - return ans
   
    return cloneHead;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << "Data: " << temp->data << ", Random: " 
             << (temp->random ? temp->random->data : -1) << endl;
        temp = temp->next;
    }
}

int main(){

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    // Setting up random pointers
    head->random = third;
    second->random = head;
    third->random = second;

    cout << "Original list:\n";
    printList(head);

    // Clone the list
    Node* clonedList = copyList(head);

    cout << "\nCloned list:\n";
    printList(clonedList);

    return 0;
}