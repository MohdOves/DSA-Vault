#include<iostream>
using namespace std;

int scope = 15;

int func(int n){
    scope++;
    cout <<"scope in func : "<<scope<<endl;
    
}
int main() {

    func(scope);


    cout <<"scope in main: "<<scope<<endl;
    
}