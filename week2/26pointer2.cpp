#include<iostream>
using namespace std;

int main() {

    // int arr[10]= {23,122,41,67};

    // cout <<"address of first memory location is "<<arr<<endl;
    // cout <<"address of first memory location is "<<&arr[0]<<endl;
    // cout <<"3 : "<<*arr<<endl;
    // cout <<"4 : "<<*arr+1<<endl;
    // cout <<"5 : "<<*(arr+1)<<endl;

    // cout <<"6 : "<<arr[2]<<endl;
    // cout <<"6 : "<<*(arr+2)<<endl;
    // cout <<"6 : "<<*(2+arr)<<endl;
    // cout <<"6 : "<<2[arr]<<endl;

    // int i = 3;
    // cout <<i[arr]<<endl;


    // int temp[10];
    // cout <<sizeof(temp)<<endl;
    // cout <<"2 "<<sizeof(*temp)<<endl;
    // cout <<"3 " <<sizeof(&temp)<<endl;

    // int *ptr = &temp[0];
    // cout <<sizeof(ptr)<<endl;
    // cout <<sizeof(*ptr)<<endl;
    // cout <<sizeof(&ptr)<<endl;


    // int a[20] = {1,2,3,5};

    // cout << &a[0]<<endl;
    // cout << &a <<endl;
    // cout <<a<<endl;

    // int *p = &a[0];
    // cout << p<<endl;
    // cout << &p<<endl;
    // cout <<*p<<endl;
    


    // int arr[10];
    
    // //ERROR;
    // //arr = arr+1;

    // int *ptr = &arr[10];
    // ptr = ptr +1;
    // cout <<ptr <<endl;




    char ch[6] = "abcde";

    cout << "1"<<ch<<endl;
    cout <<"2"<< &ch<<endl;
    cout << "3"<<*ch<<endl;

    char *c = &ch[0];
    cout <<"4"<<c <<endl;
    cout <<"5"<< *c<<endl;


    char temp = 'z';
    char *p = &temp;

    cout <<p<<endl;    


    
    }