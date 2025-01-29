#include<iostream>
#include<queue>
using namespace std;

class CircularQueue {

    int *arr;
    int front;
    int rear;
    int size;

    public:

    //initilaize data structure
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;

    }

    bool enqueue(int value){

        //to check whether queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size))) {
            cout << "Queue is Full" << endl;
            return false;
        }
        else if(front == -1){//first element to push
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == size-1 && front != 0){
            rear = 00;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    int dequeue(){

        if(front == -1){
            cout <<"Queue is Empty "<<endl;
            return -1;
        }

        int ans = arr[front];
        if(front == rear){//single element
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;//to maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }

};


int main(){

    CircularQueue q(5);

    // Testing the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << endl; // Should output 10
    q.enqueue(60);

   
    cout << q.dequeue() << endl;  // Should output 20

    return 0;
}