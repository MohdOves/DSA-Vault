#include<iostream>
using namespace std;


//just for understanding
void print(int arr[],int s,int e){
    for(int i = s;i<=e;i++){
        cout <<arr[i]<<" ";
    }cout <<endl;
}

bool binearySearch(int arr[],int st, int en,int key){

    //just for understanding
    print(arr,st,en);
    
    //base class

    //element not found
    if(st > en)
        return false;


    int mid = st + (en - st)/2;

    //element found
    if(arr[mid] == key){
        return true;
    }
        

    if(arr[mid] <key){
        return binearySearch(arr,mid+1,en,key);
        
    }
    if(arr[mid] >key){
       return binearySearch(arr,st,mid-1,key);
        
    }
    
    
}





int main() {
    int arr[5] = {2,4,6,8,9};
    int key = 89;
    int size = 5;
    int st = 0;
    int en = size;

    if(binearySearch(arr,st,en,key)){
        cout << "element found "<<endl;
    }
    else{
        cout <<"element not found "<<endl;
    }
    
    
}