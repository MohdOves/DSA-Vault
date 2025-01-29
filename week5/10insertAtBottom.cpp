#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int x){
    //base case
    if(s.empty()){
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();

    //recursive call
    solve(s,x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x){

    solve(myStack,x);
    return myStack;
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

    pushAtBottom(s,9);

    printStack(s);
}