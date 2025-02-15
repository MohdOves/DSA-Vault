#include<iostream>
#include<bits/stdc++.h>
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

void heapify(vector<int> &ans,int n,int i){

        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left <= n && ans[largest] < ans[left]){
            largest = left;
        }
        if(right <= n && ans[largest] < ans[right]){
            largest = right;
        }

        if(largest != i){
            swap(ans[largest],ans[i]);
            heapify(ans,n,largest);
        }
    }

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n,int m){

    //step 1 :merger both array into 1

    vector<int>ans;
    for(auto i:a)
        ans.push_back(i);
        
    for(auto i:b)
        ans.push_back(i);

    //step 2 : build heap using merger array
    int size = ans.size();
    for(int i = size/2-1;i>=0;i--){
        heapify(ans,size,i);
    }
    return ans;
    

    
}


int main(){

    vector<int> a = {10, 5, 6, 2}; // Max-heap 1
    vector<int> b = {12, 7, 9};    // Max-heap 2

    vector<int> mergedHeap = mergeHeaps(a, b, a.size(), b.size());

    cout << "Merged max-heap: ";
    for (int i : mergedHeap) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}