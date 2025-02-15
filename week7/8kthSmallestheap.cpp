#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    //l is the starting index
    // r is the ending index
class solution{

public:
int kthSmallest(int arr[],int l,int r , int k){
    priority_queue<int>pq;

    //step1
    for(int i = 0;i < k;i++){
        pq.push(arr[i]);
    }

    //step 2 :
    for(int i = k;i <= r;i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //ans = pq.top();
    int ans = pq.top();
    return ans;
}

};



int main(){

    int arr[] = {7, 10, 4, 3, 20, 15}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Find the 3rd smallest element

    // Create an object of class solution
    solution sol;
    cout << "The " << k << "-th smallest element is " << sol.kthSmallest(arr, 0, n - 1, k) << endl;
    
    return 0;
}