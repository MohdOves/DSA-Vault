#include<iostream>
using namespace  std;

void printArray(int arr[],int size) {
    
   
    cout <<"printing the array" <<endl;
    for (int i = 0;i<size;i++) {
        cout << arr[i]<<" ";
    }
    cout <<"printing the array is done" <<endl;
}


int main() {
    // int number[15];
    // cout <<number[0] <<endl;
    // // cout <<number[0] <<endl;


    // int second[3] = {3,6,7};
    // cout <<second[2]<<endl;


    // int third[15] = {2,4};
    // int n = 15;
    // cout <<"printing the array" <<endl;
    // for (int i = 0;i<n;i++) {
    //     cout << third[i]<<" ";
    // }


    // cout <<"ok"<<endl;



    // int fourth[10] = {0};
    //  int n = 10;
    // cout <<"printing the array" <<endl;
    // for (int i = 0;i<n;i++) {
    //     cout << fourth[i]<<" ";
    // }


    // int fifth[10] = {1};
    //      int n = 10;
    //     cout <<"printing the array" <<endl;
    //     for (int i = 0;i<n;i++) {
    //         cout << fifth[i]<<" ";
    //     }

    // int six[10];
    //  int n = 10;
    // cout <<"printing the array" <<endl;
    // for (int i = 0;i<n;i++) {
    //     six[i] = 1;
    //     cout << six[i]<<" ";
    // }


    //function wala
    int third[15] = {3,6};
    printArray(third,15);
    
    return 0;
}


