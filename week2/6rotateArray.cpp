#include<iostream>
#include<vector>
using namespace std;

void rotateArray(vector<int>&nums,int k) {
    
        vector<int>temp(nums.size());

        for(int i = 0;i <nums.size();i++){
            temp[(i+k)%nums.size()] = nums[i];
        }

        nums = temp;
    }

    int print(vector<int>nums){
        for(int i = 0;i<nums.size();i++){
            cout << nums[i]<<" ";
        }

    }


int main(){
    vector<int>v = {1,2,3,4,5,6,7};

    rotateArray(v,3);

    print(v);
}
