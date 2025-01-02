#include<iostream>
using namespace std;

int modularExponential(int x,int n,int m){
    int res= 1;

    while(n>0){
        if(n&1){
            res= (1LL * (res) * (x)%m)%m;
        }
        x = (1LL *(x)%m * (x)%m)%m;
        n = n>>1;
    }
    return res;
}



int main() {
    int x = 3;
    int n = 13;
    int m = 7;

    int result = modularExponential(x,n,m);
    cout << " the result of "<< x << "^"<<n <<" % "<<m<<" is : "<<result<<endl;

    return 0;
}