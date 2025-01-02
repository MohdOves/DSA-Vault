#include<iostream>
using namespace std;

int main() {

    int row;
    cout <<"enter the no of rows : ";
    cin>>row;

    int *col = new int[row];

    int **jagged = new int*[row];
    for(int i = 0;i<row;i++){
        cout <<"enter the no of column for row "<<i+1<<": ";
        cin>>col[i];
        jagged[i] = new int[col[i]];
    }

    //taking input
    cout <<"Enter the elements : "<<endl;
    for(int i = 0;i<row;i++){
         for(int j = 0;j<col[i];j++){
            cin>>jagged[i][j];
        }
    }

    // taking output
    cout <<" jagged array is : "<<endl;
    for(int i = 0;i<row;i++){
         for(int j = 0;j<col[i];j++){
            cout<<jagged[i][j]<<" ";
        }cout <<endl;
    }
    

     // Deallocating memory
    for(int i = 0; i < row; i++) {
        delete[] jagged[i];
    }
    delete[] jagged;
    delete[] col;
    
    return 0;
}