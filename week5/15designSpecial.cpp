#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class SpecialStack{
    
    //define data memebers
    stack<int>s;
    int mini = INT32_MAX;

    

    public:
    void push(int data){
        //for first element
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            
            if(data <mini){
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop(){
        //implement the pop() function
        if(s.empty()){
            return -1;
        }

        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }
        else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }

    }

    int top(){
        if(s.empty()){
            return -1;
        }

        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }


    bool isEmpty(){
        return s.empty();
    }

    int getMini(){
        if(s.empty()){
            return -1;
        }

        return mini;
    }


};

int main(){

    SpecialStack s;
    
    s.push(10);
    s.push(20);
    cout << "Minimum: " << s.getMini() << endl;  // Should print 10
    
    s.push(5);
    cout << "Minimum: " << s.getMini() << endl;  // Should print 5
    
    s.push(8);
    cout << "Top: " << s.top() << endl;  // Should print 8
    cout << "Minimum: " << s.getMini() << endl;  // Should still print 5
    
    cout << "Popped: " << s.pop() << endl;  // Should print 8
    cout << "Minimum: " << s.getMini() << endl;  // Should still print 5
    
    cout << "Popped: " << s.pop() << endl;  // Should print 5
    cout << "Minimum: " << s.getMini() << endl;  // Should print 10
    
    return 0;
}