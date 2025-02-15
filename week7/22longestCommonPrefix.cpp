// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// string longestCommonPrefix(vector<string>& arr,int n){

//     string ans = "";

//     //for traversing all character of first string
//     for(int i = 0;i<arr[0].length();i++){
//         char ch = arr[0][i];

//         bool match = true;

//     //for comparing character with reat of the string
//         for(int j = 1;j<n;j++){
//             //not match
//             if(arr[j].size() < i || ch != arr[j][i]){
//                 match = false;
//                 break;
//             }
//         }
//         if(match == false)
//             break;
//         else
//             ans.push_back(ch);
//     }
//     return ans;
// }

// int main(){

//     vector<string> arr = {"flower", "flow", "flight"};
//     int n = arr.size();

//     string result = longestCommonPrefix(arr, n);
//     cout << "Longest Common Prefix: " << result << endl;

//     return 0;
// }




//APPROACH 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    char data;
    trieNode* children[26];
    int childCount;
    bool isTerminal;

    trieNode(char ch){
        data = ch;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    trieNode* root;

    Trie(char ch){
        root = new trieNode(ch);
    }

     void insertUtil(trieNode* root,string word){

        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        
        int index = word[0] - 'a';
        trieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new trieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        //RECURSION
        insertUtil(child,word.substr(1));

    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void lcp(string str,string& ans){

        for(int i = 0;i<str.length();i++){
            char ch = str[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                //aage badh jao
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }


};

string longestCommonPrefix(vector<string>& arr,int n){
    Trie* t = new Trie('\0');

    //insert karde all string into trie
    for(int i = 0;i<n;i++){
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first,ans);
    return ans;

}

int main(){

    vector<string> arr = {"flower", "flow", "flight"};
    int n = arr.size();

    string result = longestCommonPrefix(arr, n);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}


