#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string FirstNonRepeating(string A){
        unordered_map<char,int>count;
        queue<int>q;
        string ans = "";

        for(int i = 0;i<A.length();i++){
            char ch = A[i];

            //increase count
            count[ch]++;

            //queue me push karo
            q.push(ch);

            while(!q.empty()){
                if(count[q.front()] > 1){

                    //repeating character
                    q.pop();
                }
                else{
                    //non repeating char mil gaya
                    ans.push_back(q.front());
                    break;
                }
            }

            if(q.empty()){
                ans.push_back('#');
            }
            
        }
        return ans;
    }
};

int main() {
  
     Solution sol;
    string A = "aabc";
    cout << "Result: " << sol.FirstNonRepeating(A) << endl;
    return 0;
    
}
