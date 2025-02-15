// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int getKthLargest(vector<int>& arr,int k){

//     vector<int> sumStore;
//     int n = arr.size();
//     for(int i =0;i<n;i++){
//         int sum = 0;
//         for (int j = i;j<n;j++){
//             sum += arr[j];
//             sumStore.push_back(sum);
//         }     
//     }
//     sort(sumStore.begin(),sumStore.end());
//     return sumStore[sumStore.size()- k];
// }



// int main(){

//     vector<int> arr = {3, 2, 1}; // Example array
//     int k = 2; // Example k

//     cout << "The " << k << "-th largest subarray sum is " << getKthLargest(arr, k) << endl;

//     return 0;
// }



//APPROACH 2

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int getKthLargest(vector<int>& arr,int k){

    priority_queue<int,vector<int>,greater<int>>mini;

    int n = arr.size();
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += arr[j];
            if(mini.size() < k){
                mini.push(sum);
            }
            else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
            
        }
    }
    return mini.top();
}


int main(){

    vector<int> arr = {3, 2, 1};
    int k = 2;

    cout << "The " << k << "-th largest subarray sum is " << getKthLargest(arr, k) << endl;

    return 0;
}