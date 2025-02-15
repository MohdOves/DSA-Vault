#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){

    priority_queue<Node*,vector<Node*>,compare >minHeap;

    int k = listArray.size();

    if(k== 0){
        return NULL;
    }
    //step1;
    for(int i = 0;i<k;i++){
       if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(minHeap.size() > 0){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){
            //answer LL is empty
            head = top;
            tail = top;
            
        }
        else{
            //insert at LL
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create example linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* list3 = new Node(2);
    list3->next = new Node(6);

    vector<Node*> listArray = {list1, list2, list3};

    Node* mergedHead = mergeKLists(listArray);

    // Print the merged linked list
    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}
