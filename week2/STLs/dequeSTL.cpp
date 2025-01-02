#include<iostream>
#include<deque>
using namespace std;

int main() {

    deque<int>d;

    d.push_back(1);
    d.push_front(2);

    for(int i:d){
        cout <<i<<" ";
    }
    cout <<endl;



    // d.pop_back();
    // cout <<endl;
    // for(int i:d){
    //     cout <<i<<" "<<endl;
    // }

    // d.pop_front();
    // cout <<endl;
    // for(int i:d){
    //     cout <<i<<" "<<endl;
    // }



    cout << "print first index element : "<<d.at(1)<<endl;
        
    cout <<"front : "<<d.front()<<endl;
    cout <<"back : "<<d.back()<<endl;

    cout <<"Empty or not : "<<d.empty()<<endl;

    cout<<"Before Erase "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout <<"after Erase : "<<d.size()<<endl;
    for(int i:d){
        cout <<i<<endl;
    }
    

}