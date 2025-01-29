#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&inputStack,int count,int size){

    //base case 
    if(count == size/2){
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    //recursive call
    solve(inputStack,count+1,size);

    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack,int N){

    int count = 0;
    solve(inputStack,count,N);
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

    deleteMiddle(s,s.size());

    printStack(s);

    


    return 0;
}