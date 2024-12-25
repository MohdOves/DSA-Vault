#include<iostream>
using namespace std;

void findIntersection(int arr1[],int n,int m,int arr2[]) {

    int i=0,j=0;
    int ans;
    while(i<n && j<m){
        if(arr1[i] == arr2[j]){
            cout << arr1[i]<<" ";   
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else {
            j++;
        }
    }
}

int main(){
    int arr1[6] = {1,2,2,2,3,4};
    int arr2[3] = {2,2,3};

   cout<<"intersection elements are : ";
   findIntersection(arr1,6,3,arr2);
    cout <<endl;

    return 0;
}