#include<iostream>
using namespace std;


int firstOccurance(int arr[],int n , int key) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e) {
        if(arr[mid] == key){
            ans = mid;
            e = mid-1;
        }
        else if(key > arr[mid]){
            s = mid +1;
        }
        else if(key < arr[mid]) {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }

return ans;
}


int lastOccurance(int arr[],int n , int key) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e) {
        if(arr[mid] == key){
            ans = mid;
            s = mid+1;
        }
        else if(key > arr[mid]){
            s = mid +1;
        }
        else if(key < arr[mid]) {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }

return ans;
}

int main() {
    int even[11] = {1,2,3,3,3,3,3,3,3,3,4};

    cout << " first occurance of 3 is at Index " <<firstOccurance(even,11,3)<<endl;
    cout << " last occurance of 3 is at Index " <<lastOccurance(even,11,3)<<endl;

    cout << " no of occurance of 3 is at Index " <<(lastOccurance(even,11,3) - firstOccurance(even,11,3)) + 1<<endl;

    return 0;
}