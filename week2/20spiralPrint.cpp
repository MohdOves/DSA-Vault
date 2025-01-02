#include<iostream>
#include<vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix){
v
    ector<int>ans;

    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row*col;

//index intialisation
    int startingRow =0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;


    while(count <total){

        //printing starting row
        for(int index = startingCol;count <total && index <= endingCol; index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        //printing ending col
        for(int index = startingRow; count <total && index<=endingRow; index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        } 
        endingCol--;

        //printing ending row
        for(int index = endingCol; count <total &&  index >=startingCol; index--){
            ans.push_back(matrix[endingRow][index]);
            count++;

        }
        endingRow--;

        //printing starting col
        for(int index = endingRow;count <total && index >=startingRow; index--){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}


int main() {

    vector<vector<int>>v = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int>ans = spiralOrder(v);

    for(int i : ans){
        cout << i <<" ";
    }

}