#include<iostream>
using namespace std;


void selectionSort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

    
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[5] = {3,65,74,5,8};
    
    selectionSort(arr,5);
    printArray(arr,5);
    
    return 0;
}