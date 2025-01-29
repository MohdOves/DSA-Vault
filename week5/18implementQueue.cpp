#include<iostream>
#include<queue>
using namespace std;

class Queue{

    int* arr;
    int front;
    int rear;
    int size;

    public:
    Queue(){
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }


    void enQueue(int data){

        if(rear == size){
            cout <<"queue is full "<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){

        if(rear == front){
            cout <<"queue is empty"<<endl;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int getFront(){
        if(front == rear){
            cout <<"queue is empty"<<endl;
        }
        else{
            return arr[front];
        }
    }
};

int main(){

    Queue q;
    
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;       
    cout << "Front element: " << q.getFront() << endl; 

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Dequeue: " << q.dequeue() << endl;        
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; 


    return 0;
    

}