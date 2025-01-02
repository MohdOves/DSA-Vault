#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;

    vector<int>a(5,1);
    cout<<"print a"<<endl;
    for(int i:a){
        cout <<i<<" ";
    }cout <<endl;


    cout <<"Capacity : "<<v.capacity()<<endl;

    v.push_back(1);
    cout <<"Capacity : "<<v.capacity()<<endl;

    v.push_back(2);
    cout <<"Capacity : "<<v.capacity()<<endl;

    v.push_back(3);
    cout <<"Capacity : "<<v.capacity()<<endl;

    cout <<"Size : "<<v.size()<<endl;

    cout <<"Element at 2 index : "<<v.at(2)<<endl;

    cout <<"front : "<<v.front()<<endl;
    cout <<"back : "<<v.back()<<endl;


    cout<<"Before pop "<<endl;
    for(int i:v){
        cout <<i<<" ";
    }cout <<endl;

    v.pop_back();

    cout<<"after pop "<<endl;
    for(int i:v){
        cout <<i<<" ";
    }cout <<endl;


    cout <<"Before clear size : "<<v.size()<<endl;
    v.clear();
    cout <<"After clear size : "<<v.size()<<endl;





}