#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

queue<int> rev(queue<int>q){

    stack<int>s;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
    
}

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    

    // Reversing the queue
    q = rev(q);

    // Displaying reversed queue
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
