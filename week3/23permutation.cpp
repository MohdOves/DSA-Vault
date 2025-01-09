#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums,vector<vector<int>>& ans,int index){

    //base case
    if(index >=nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int j = index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        //backTrack
        swap(nums[index],nums[j]);


    }
}

vector<vector<int>> permutation(vector<int>& nums){
    vector<vector<int>> ans;
    int index = 0;
    solve(nums,ans,index);
    return ans;
}

int main(){
     // Test case
    vector<int> nums = {1, 2, 3};  // Example input

    // Get all permutations
    vector<vector<int>> result = permutation(nums);

    // Print all permutations
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}