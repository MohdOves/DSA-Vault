#include<iostream>
#include<stack>
using namespace std;

class Stack{

    //prperties
    int* arr;
    int top;
    int size;


    //behaviour
    public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size-top >1){
            top++;
            arr[top] = element;
        }
        else{
            cout <<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top >=0){
            top--;
        }
        else{
            cout <<"Stack is Underflow"<<endl;
        }
    }
    

    int peek(){
        if(top >=0){
        return arr[top];
        }
        else{
            cout <<"Stack is Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    // //creation of stack
    // stack<int>s;

    // //push operation
    // s.push(2);
    // s.push(3);

    // //pop operation
    // s.pop();

    // //top operation
    // cout <<"printing top element "<<s.top()<<endl;

    // //empty operation
    // if(s.empty()){
    //     cout <<"stack is empty"<<endl;
    // }
    // else{
    //     cout <<"stack is not empty"<<endl;
    // }

    // cout<<"size of stack is "<<s.size()<<endl;



    Stack st(6);

    st.push(22);
    st.push(43);
    st.push(44);

    st.push(22);
    st.push(43);
    st.push(44);

    cout <<st.peek()<<endl;

    st.pop();
    cout <<st.peek()<<endl;

    st.pop();
    cout <<st.peek()<<endl;

    st.pop();
    cout <<st.peek()<<endl;

    if(st.isEmpty()){
        cout <<"stack is Empty "<<endl;
    }
    else{
        cout <<"stack is not Empty"<<endl;                  
  return 0;  
} 
}
