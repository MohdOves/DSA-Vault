#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{

    private:
    bool knows(vector<vector<int>>& M, int a,int b,int n){

        if(M[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    }

    public:
    int celebrity(vector<vector<int>>& M,int n){

        stack<int>s;

        //step1: push all element in stack
        for(int i = 0;i<n;i++){
            s.push(i);
        }

        //step 2 get 2 element and compare

        while(s.size() > 1){
            
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }

        int ans = s.top();

        //step3 : single element in stack is potential celebrity
        //so verify it

        
        int zeroCount = 0;
        for(int i = 0;i<n;i++){
            if(M[ans][i] == 0)
                zeroCount++;
        }

        //all zeros
        if(zeroCount != n)
            return -1;
        

        //column check
        
        int oneCount = 0;

        for(int i = 0;i<n;i++){
            if(M[i][ans] == 1)
                oneCount++;
        }

    if(oneCount != n-1)
        return -1;
    

    return ans;

    }
};

int main(){

    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 0}
    };

    Solution sol;
    int n = 3;
    int result = sol.celebrity(M, n);

    if(result == -1){
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is person " << result << endl;
    }

    return 0;
    
}