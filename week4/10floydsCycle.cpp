#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to detect a cycle in the linked list using Floyd's Cycle Detection Algorithm
Node* detectCycle(Node* head) {
    if (head == NULL) 
    return NULL;

    Node* slow = head;
    Node* fast = head;

    // Traverse the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // Move slow by 1 step
        fast = fast->next->next;   // Move fast by 2 steps

        // If slow and fast meet, there is a cycle
        if (slow == fast) {
            return slow;
        }
    }

    return NULL;  // No cycle detected
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* getStartedNode(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* intersection = detectCycle(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection= intersection->next;
    }
    return slow;
}


void removeLoop(Node* head){
    if(head == NULL){
        return;
    }
    
    Node* startOfLoop = getStartedNode(head);
    Node* temp =startOfLoop;

    while(temp ->next != startOfLoop){
        temp = temp->next;
    }

    temp ->next = NULL;
}




int main() {
    // Creating nodes
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    Node* node5 = new Node(50);

    // Linking nodes to form a list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

  
    node5->next = node3;  // Creates a cycle back to node3

    // Detect cycle in the linked list
    if (detectCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }


    Node* loop = getStartedNode(head);
    cout <<"loop starts at "<<loop->data<<endl;


    removeLoop(head);
    print(head);
    return 0;
}
