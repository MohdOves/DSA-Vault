// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     //constructor
//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//     }
// };

// Node* sortList(Node* head){

//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;

//     Node* temp = head;

//     while(temp != NULL){
//         if(temp->data == 0)
//             zeroCount++;

//         else if(temp->data == 1)
//             oneCount++;

//         else if(temp->data = 2)
//             twoCount++;

//         temp = temp->next;
//     }

//     temp = head;
//     while(temp != NULL){
//         if(zeroCount != 0){
//             temp->data = 0;
//             zeroCount--;
//         }
//         else if(oneCount != 0){
//             temp->data = 1;
//             oneCount--;
//         }
//         else if(twoCount != 0){
//             temp->data = 2;
//             twoCount--;
//         }
//         temp = temp->next;
//     }
//     return head;
// }

// void print(Node* head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout <<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout <<endl;
// }


// int main(){

//     Node* node1= new Node(1);
//     Node* head = node1;

//     Node* node2 = new Node(0);
//     Node* node3 = new Node(1);
//     Node* node4 = new Node(2);
//     Node* node5 = new Node(1);
//     Node* node6 = new Node(2);
//     Node* node7 = new Node(1);

//     head->next = node2;
//     node2->next = node3;
//     node3->next = node4;
//     node4->next = node5;
//     node5->next = node6;
    

    



//     print(head);

//     sortList(head);
//     print(head);

// }



//APPROACH 2

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

void insertAtTail(Node* &tail,Node* curr){
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node* head){

    Node* zeroHead = new Node(-1); // Dummy node for zero list
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);  // Dummy node for one list
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);  // Dummy node for two list
    Node* twoTail = twoHead;

    Node* curr = head;

    // Separate nodes into three lists: 0s, 1s, and 2s
    while(curr != NULL){
        int value = curr->data;

        if(value == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1){
            insertAtTail(oneTail, curr);
        }
        else if(value == 2){
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // Merge lists
    // Connect zero list to one list if it's not empty; otherwise to two list
    if(oneHead->next != NULL){ 
        zeroTail->next = oneHead->next;
    }
    else { 
        zeroTail->next = twoHead->next;
    }

    // Connect one list to two list
    oneTail->next = twoHead->next;
    twoTail->next = NULL;  // End the two list

    // Set up the new head
    head = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* node1= new Node(1);
    Node* head = node1;

    Node* node2 = new Node(0);
    Node* node3 = new Node(1);
    Node* node4 = new Node(2);
    Node* node5 = new Node(1);
    Node* node6 = new Node(2);
    Node* node7 = new Node(0);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    cout << "Original List: ";
    print(head);

    head = sortList(head);

    cout << "Sorted List: ";
    print(head);
}
