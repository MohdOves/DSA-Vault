#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i = 1;i<n;i++){

        int temp = arr[i];

        int j = i-1;
        for(;j>=0;j--){

            if(arr[j] > temp){

                //shift
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;

    }
}

int printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout << arr[i]<<" ";
    }
}

int main(){

    int arr[11] = {1,4,2,7,75,0,23,234,664,8,5466};

    insertionSort(arr,11);
    printArray(arr,11);

    return 0;
}