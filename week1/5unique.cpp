#include<iostream>
using namespace std;


int uniqueNumber(int arr[],int size) {
    int ans = 0;
    for(int i = 0;i<size;i++) {
        ans = ans^arr[i];
    }
    return ans;
}


int main() {
    int arr[5] = {1,4,2,4,2};
    int result = uniqueNumber(arr,5);
    cout <<"the unique number is : "<<result<<endl;
    return 0;
}