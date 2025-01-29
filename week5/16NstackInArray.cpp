#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class NStack{
    int* arr;
    int *top;
    int* next;

    int n,s;
    int freespot;

    public:
    //initilize you data stucture
    NStack(int N,int S){

        n = N;
        s = S;
        arr= new int[s];
        top = new int[n];
        next = new int[s];

        //top intilize
        for(int i = 0;i<n;i++){
            top[i] = -1;
        }



        //next intilize
        for(int i = 0;i<s;i++){
            next[i] = i+1;
        }

        //update last index value to -1
        next[s-1] = -1;

        //initilize freespot
        freespot = 0;


    }

    //push 'X' into the Mth stack,return true if it gets pushed
    bool push(int x,int m){

        //check overflow
        if(freespot == -1  ){
            return false;
        }

        //find index 
        int index = freespot;

        //update freespot
        freespot = next[index];

        //insert element into array
        arr[index]= top[m-1];

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1]  = index;

        return true;



    }

    //pop top element from Mth stack, return -1 if the stack is empty
    int pop(int m){

        //check underflow condition
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];

    }

};

int main(){

      NStack ns(3, 6); // 3 stacks and an array size of 6

    ns.push(10, 1);  // Push 10 into stack 1
    ns.push(20, 1);  // Push 20 into stack 1
    ns.push(30, 2);  // Push 30 into stack 2
    ns.push(40, 2);  // Push 40 into stack 2
    ns.push(50, 3);  // Push 50 into stack 3

    cout << "Pop from stack 1: " << ns.pop(1) << endl; // Should return 20
    cout << "Pop from stack 2: " << ns.pop(2) << endl; // Should return 40
    cout << "Pop from stack 3: " << ns.pop(3) << endl; // Should return 50

    return 0;
    
    
}