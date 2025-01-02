#include<iostream>
using namespace std;


char getMaximumCharacter(string s){

    int arr[26] = {0};


    //create an araay of count of character
    for(int i = 0;i<s.length();i++){
        char ch = s[i];


    //lower case
        int number = 0;
        if(ch >= 'a' && ch <='z'){
            number= ch- 'a';
        }

        //uppercase
        else{
            number = ch - 'A';
        }
        arr[number]++;
    }


    //find maximum occurance character
    int maxi = -1,ans = 0;
    for(int i = 0;i<26;i++){

        if(maxi <arr[i]){
            ans = i;
            maxi = arr[i];
        }
     
    }

    char  findAns = 'a'+ ans;
    return findAns;
}



int main(){

    string s;
    cin>>s;
    cout << getMaximumCharacter(s);

}