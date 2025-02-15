#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;  
    }
};

long long minCost(long long arr[],long long n){

    priority_queue<long long,vector<long long>,greater<long long>>pq;

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    long long cost = 0;

    while(pq.size() > 1){
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a+b;
        cost += sum;

        pq.push(sum);

    }
    return cost;
}

int main() {
  
    long long arr[] = {4, 3, 2, 6}; // Example array of ropes
    long long n = sizeof(arr) / sizeof(arr[0]);

    cout << "The minimum cost to connect ropes is " << minCost(arr, n) << endl;

    return 0;
}
