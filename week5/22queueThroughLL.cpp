#include <bits/stdc++.h> 
using namespace std;

class node{
    public:
     int data;
     node* next;

     node(int d){
         data = d;
         next = NULL;
     }
};

class Queue {

    node* Front;
    node* rear;


public:
    Queue() {
        // Implement the Constructor
        Front = NULL;
        rear = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(Front == NULL)
            return true;
        else return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        node* temp = new node(data);

        if(rear == NULL){
            rear = temp;
            Front = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }

    }

    int dequeue() {
        // Implement the dequeue() function
        if(Front == NULL)
            return -1;
        
        int val = Front->data;
        node* temp = Front;
        Front = Front->next;
        if(Front == NULL){
            rear = NULL;
        }
        free(temp);
        return val;
    }

    int front() {
        // Implement the front() function
        if(Front == NULL)
            return -1;
        
        return Front->data;
    }
};