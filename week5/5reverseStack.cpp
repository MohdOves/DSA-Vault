#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& stack, int element){
    //base case
    if(stack.empty()){
        stack.push(element);
        return ;
    }

    int num = stack.top();
    stack.pop();
    
    //recursive call
    insertAtBottom(stack,element);

    stack.push(num);
}

void reverseStack(stack<int>& stack){
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    reverseStack(stack);

    insertAtBottom(stack,num);



}

void printStack(stack<int> s) {
    // Printing elements from top to bottom
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}



int main(){
     stack<int>s;

    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    
    printStack(s);

    reverseStack(s);

    printStack(s);
}