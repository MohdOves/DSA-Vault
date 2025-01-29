#include<iostream>
#include<queue>
using namespace std;

class Deque{

    int* arr;
    int front;
    int rear;
    int size;

    public:
    //intilize the data structure
    Deque(int n){
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x){
        //check full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size))){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;

    }

    bool pushRear(int x){

        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size))){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
          }
        else if(rear == size-1 && front != 0){
            rear = 0;
          }
        else{
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    int popFront(){

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

    int popRear(){

        if(front == -1){
            cout <<"Queue is Empty "<<endl;
            return -1;
        }

        int ans = arr[rear];

        if(front == rear){//single element
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;//to maintain cyclic nature
        }
        else{
            rear--;
        }
        return ans;
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size))){
            return true;
        }
        else{
            return false;
        }
    }

};


int main(){

     Deque dq(5);

    // Testing deque operations
    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(30);
    dq.pushFront(40);

    cout << "Front element: " << dq.getFront() << endl;  // Should output 40
    cout << "Rear element: " << dq.getRear() << endl;    // Should output 20

    dq.popFront();  // Should remove 40
    cout << "Front element after pop: " << dq.getFront() << endl;  // Should output 30

    dq.popRear();   // Should remove 20
    cout << "Rear element after pop: " << dq.getRear() << endl;    // Should output 10

    return 0;
}