#include<iostream>
#include<vector>
using namespace std;

void solve(string str,string output,int index,vector<string> &ans){

    //base case
    if(index >= str.length()){
        ans.push_back(output);
        return ;
    }

    //exclude
    solve(str,output,index+1,ans);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);
}

vector<string> subsequences(string str) {

    vector<string>ans;
    string output = "";
    int index = 0;
    solve(str,output,index,ans);
    return ans;
}

int main() {

    string str = "abc";

    // Get all subsequences
    vector<string> result = subsequences(str);

    // Print the subsequences
    for (const auto& subsequence : result) {
        cout << "\"" << subsequence << "\"" << endl;
    }
    return 0;
}