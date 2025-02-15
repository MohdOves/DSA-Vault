#include<bits/stdc++.h>
//#include<map>
//#include<unordered_map>
using namespace std;


int main(){

    //creation
    unordered_map<string,int> m;

    //insertion

    //type 1
    pair<string,int> p = make_pair("babbar",3);
    m.insert(p);

    //type 2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    //type 3
    m["mera"] = 1;

    //what will happen ?
    m["mera"] = 2;
    //ans : updation take place change from 1 to 2


    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

    // cout<<m.at("unknownKey")<<endl;//error
    cout<<m["unknownKey"]<<endl;//0
    cout<<m.at("unknownKey")<<endl;//0

    //size
    cout<<m.size()<<endl;//4

    //to check presence
    cout<<m.count("bro")<<endl;//0
    cout<<m.count("babbar")<<endl;//1

    //Erase
    m.erase("love");
    cout<<m.size()<<endl;//3


    //traverse

    //type 1
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //type 2 : iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<< it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}