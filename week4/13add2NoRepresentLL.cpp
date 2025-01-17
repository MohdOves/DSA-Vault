#include<iostream>
#include<vector>
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

class Solution{
    private:
    Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    }


void insertAtTail(Node* &head,Node* &tail,int val){

    Node* temp = new Node(val);
    //empty list
    if(head == NULL){
        head = temp;
        tail = head;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

    Node* add(Node* first, Node* second){
        int carry = 0;

        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){

            int val1 = 0;
            if(first != NULL)
                val1 = first ->data;
            
            int val2 = 0;
            if(second != NULL)
                val2 = second->data;
            

            int sum = carry+ val1 + val2;

            int digit = sum % 10;

            //create node and add in answer linekd list
            insertAtTail(ansHead,ansTail,digit);

            carry = sum/10;
            
            if(first != NULL)
                first = first->next;
            
            if(second != NULL)
                second = second->next;
        }

       
        return ansHead;
    }

   public:
   Node* addTwoList( Node* first, Node* second){

        //step1 reverse input ll
    first = reverse(first);
    second = reverse(second);

    //step2 - add 2 LL
    Node* ans = add(first,second);

    //step3- reverse the ans
    ans = reverse(ans);

    return ans;

   }
    
   
};

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main(){
        Solution sol;

    // List 1: 3 -> 4 -> 2 (Represents number 243)
    Node* first = new Node(3);
    first->next = new Node(4);
    first->next->next = new Node(2);

    // List 2: 4 -> 6 -> 5 (Represents number 564)
    Node* second = new Node(4);
    second->next = new Node(6);
    second->next->next = new Node(5);

    print(first);
    print(second);

    // Adding the two lists: 243 + 564 = 807
    Node* ans = sol.addTwoList(first, second);

     
    print(ans);
    return 0;
}

