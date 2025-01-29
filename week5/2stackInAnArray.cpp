#include<iostream>
using namespace std;

class TwoStack{
    int* arr;
    int top1;
    int top2;
    int size;

    public:
    TwoStack(int s){
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    //push in stack1
    void push1(int num){
        if(top2 - top1 > 1){
            top1++;
            arr[top1]= num;
        }
        else{
            cout <<"stack Overflow"<<endl;
        }
    }


    //push instack 2
    void push2(int num){
        if(top2 - top1 > 1){
            top2--;
            arr[top2]= num;
        }
        else{
            cout <<"stack Overflow"<<endl;
        }
    }



    //pop from stack1 and retruned pop element
    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    //pop from stack2
    int pop2(){
         if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
         return -1;
        }
    }

    
    

    void printStack1() {
        if (top1 == -1) {
            cout << "Stack 1 is empty" << endl;
        } else {
            cout << "Stack 1 elements: ";
            for (int i = top1; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Print all elements in stack2
    void printStack2() {
        if (top2 == size) {
            cout << "Stack 2 is empty" << endl;
        } else {
            cout << "Stack 2 elements: ";
            for (int i = top2; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Get size of the total array (both stacks)
    int getSize() {
        return size;
    }
};

int main(){

    TwoStack st(10);

    st.push1(3);
    st.push1(4);
    

    st.push2(10);
    st.push2(9);

    st.pop1();
    st.pop2();
    

    st.getSize();

    st.printStack1();
    st.printStack2();

    return 0;
}