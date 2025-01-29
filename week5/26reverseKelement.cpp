#include<iostream>
#include<bits/stdc++.h>
using namespace std;

queue<int>modifyQueue(queue<int>q,int k){
    //algo

    //step 1 pop first k element from queue and put into stack

    stack<int>s;

    for(int i = 0;i<k;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //step 2 fetch from stack and push into queue
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    //step 3 fetch first n-k element from queue and push back

    int t = q.size()-k;

    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;


}

int main() {
  
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3; // Number of elements to reverse from the front

    // Modify the queue
    queue<int> modifiedQueue = modifyQueue(q, k);

    // Display the modified queue
    cout << "Modified queue: ";
    while(!modifiedQueue.empty()) {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }

    return 0;
   
    return 0;
}
