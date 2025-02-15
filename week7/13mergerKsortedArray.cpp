#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;
    node(int data,int row,int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays,int k){
    priority_queue<node*,vector<node*>,compare> miniHeap;

    //step1: saare array k first element insert h
    for(int i = 0; i<k;i++){
        node* temp = new node(kArrays[i][0],i,0);
        miniHeap.push(temp);
    }

    vector<int>ans;
    //step 2:
    while(miniHeap.size() > 0){
        node* temp = miniHeap.top();

        ans.push_back(temp->data);
        miniHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            miniHeap.push(next);
        }
    }
    return ans;
}


int main(){

        vector<vector<int>> kArrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int k = kArrays.size();

    vector<int> result = mergeKSortedArrays(kArrays, k);
    cout << "Merged array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;

}