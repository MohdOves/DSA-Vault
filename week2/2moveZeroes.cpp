#include<iostream>
#include<vector>
#include<array>
using namespace std;


void moveZeroes(vector<int>&  nums) {
    int nonZero = 0;

    for(int j = 0;j<nums.size();j++){
        if(nums[j] !=0) {
            swap(nums[j],nums[nonZero]);
            nonZero++;

        }
    }
}

int printArray(vector<int>&nums){
    for(int i = 0;i<nums.size();i++){
        cout <<nums[i]<<" ";
    }
}



int main() {

    vector<int>v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(0);
    v.push_back(0);
    v.push_back(12);

    moveZeroes(v);

    printArray(v);

    
    
}