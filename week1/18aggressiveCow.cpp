#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isPossible(vector<int>& stalls,int k,int mid){
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i=0;i<stalls.size();i++){

        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
    
}



int aggresiveCow(vector<int>& stalls,int k){

    sort(stalls.begin(),stalls.end());

    int s = 0;
    int maxi = -1;
    for(int i = 0;i<stalls.size();i++){
        maxi = max(maxi,stalls[i]);
    }

    int e = maxi;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e) {
        if(isPossible(stalls,k,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    int n, k;
    cout << "Enter the number of stalls: ";
    cin >> n;
    vector<int> stalls(n);

    cout << "Enter the stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    cout << "Enter the number of cows: ";
    cin >> k;

    int result = aggresiveCow(stalls, k);
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}