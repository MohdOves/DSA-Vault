#include<iostream>
using namespace std;

char toLowerCase(char ch){
    if(ch >='a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}


bool checkpalindrome(char arr[],int n){
    int s = 0;
    int e = n-1;

    while(s<e){
        if(toLowerCase(arr[s]) != toLowerCase(arr[e])){
            return 0;
            
        }
        else{
            s++;
            e--;;
        }
    }
    return 1;
}

int getLength(char name[]){
    int count = 0;
    for(int i = 0;name[i] != '\0';i++){
        count++;
    }
    return count;
}


int main() {

    
    char arr[5];
    cout <<" enter your character : "<<endl;
    cin>>arr;

     int len = getLength(arr);

    cout <<"palindrome or not : "<<checkpalindrome(arr,len)<<endl;

    
}