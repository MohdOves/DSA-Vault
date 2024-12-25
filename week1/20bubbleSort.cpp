#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout <<arr[i]<<" ";
    }
}

int main() {
    int arr[5] = {2,6,7,3,1};

    bubbleSort(arr,5);
    printArray(arr,5);

    return 0;
}


