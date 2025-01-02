#include<iostream>
using namespace std;

int main() {
//     int num = 5;
//     cout <<&num<<endl;

//     int *ptr = &num;
//     cout <<" value is : "<<*ptr<<endl;
//     cout <<" value is : "<<ptr<<endl;

//     double d = 4.3;
//     double *p2 = &d;
//     cout <<" value is : "<<*p2<<endl;
//     cout <<" value is : "<<p2<<endl;


//     cout <<"size of integer is : "<<sizeof(num)<<endl;
//     cout <<"size of integer is : "<<sizeof(ptr)<<endl;
//     cout <<"size of double is : "<<sizeof(p2)<<endl;
   


    // bad practice  pointing to garbasge value
    // int *p;
    // cout <<*p<<endl;


    // method to intilize the pointer
    // int i = 5;

    // int *q = &i;
    // cout << q <<endl;
    // cout << *q<< endl;


    // int *p = 0;
    // p = &i;
    // cout << p <<endl;
    // cout << *p<< endl;



    int num = 5;
    cout <<"a before"<<num<<endl;
    int a = num;
    a++;
    cout <<"a after"<<num<<endl;

   
    
    int *p = &num;
    
    cout <<"before"<<num<<endl;
    (*p)++;
    cout << "after"<<num <<endl;
 

    //copying a pointer
    int *q = p;
    cout <<p <<" "<<q<<endl;
    cout <<*p<<" "<<*q<<endl;


    //important concept 

    int i = 3;
    int *t = &i;

    // (*t)++;
    // cout <<*t;


    cout <<" before t"<<t<<endl;
    t = t+1;
    cout <<" after t "<<t;

    
}



