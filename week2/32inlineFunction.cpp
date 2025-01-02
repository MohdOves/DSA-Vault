// #include<iostream>
// using namespace std;

// void func(int a,int b){

//     a++;
//     b++;
//     cout <<a<<b<<endl;
// }

// int main() {

//     int a = 1,b=2;
//     func(a,b);
   
// }



#include<iostream>
using namespace std;


inline int getMax(int& a,int& b){
    return (a>b) ? a:b;
}


int main() {

    int a = 1,b=2;
    int ans = 0;


    // if(a>b){
    //     ans = a;
    // }
    // else{
    //     ans = b;
    // }

    // same answer in teritary operator
    // ans = (a>b) ? a:b;

    // a = a+2;
    // b = b+1;

    // ans = (a>b) ? a:b;


    // function wala

    ans = (a>b) ? a:b;
    cout <<ans <<endl;
    
    a = a+3;
    b = b+1;

    ans = (a>b) ? a:b;
    cout <<ans <<endl;

   
}