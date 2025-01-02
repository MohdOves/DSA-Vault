#include<iostream>
using namespace std;

// to print row wise sum
void printRowSum(int arr[][3], int row,int col){
    cout <<" printing  Row Sum -> "<<endl;


    for(int row = 0;row<3;row++){
        int sum = 0;
        for(int col = 0;col<3;col++){
            sum += arr[row][col];
        }
        cout << sum <<" ";
        
    }
    cout <<endl;
}


//to print column wise
void printColSum(int arr[][3], int row,int col){
    cout <<" printing  Column Sum  -> "<<endl;


    for(int col = 0;col<3;col++){
        int sum = 0;
        for(int row = 0;row<3;row++){
            sum += arr[row][col];
        }
        cout << sum <<" ";
        
    }
    cout <<endl;
}


int largestRowSum(int arr[][3], int row, int col){

    int maxi = INT32_MIN;
    int rowIndex = -1;
    for(int col = 0;col<3;col++){
        int sum = 0;
        for(int row = 0;row<3;row++){
            sum += arr[row][col];
        }
        if(sum >maxi) {
            maxi = sum;
            rowIndex = row;

        }
    }
    cout <<"the maximum sum is : "<<maxi <<endl;
    return rowIndex;


}


int main() {

    //create 2D array
    int arr[3][3];

    cout <<"Enter the Elements : "<<endl;

    for(int row = 0;row<3;row++){
        for(int col = 0;col<3;col++){
            cin >> arr[row][col];
        }
    }

    
    //print 
    
    for(int row = 0;row<3;row++){
        for(int col = 0;col<3;col++){
            cout << arr[row][col]<<" ";
        }
        cout <<endl;
    }

   

    printRowSum(arr,3,3);
    printColSum(arr,3,3);

    int ansIndex = largestRowSum(arr,3,3);
    cout <<"max row is at index  : "<<ansIndex<<endl;
   

}