// #include<bits/stdc++.h>
// using namespace std;

// class graph{

//     public:
//     unordered_map<int,list<int>>adj;

//     void addEdge(int u,int v,bool direction){
//         //direction = 0 ->undirected
//         //direction = 1 -> directed graph

//         //create an edge from u to v
//         adj[u].push_back(v);

//         if(direction == 0){
//             //for directed v to u
//             adj[v].push_back(u);
//         }
//     }

//     void printAdjlist(){
//         for(auto i: adj){
//             cout<<i.first<<"->";
//             for(auto j:i.second){
//                 cout<<j<<",";
//             }
//             cout <<endl;
//         }
//     }
// };

// int main(){

//     int n;
//     cout<<"enter ther number of nodes:"<<endl;
//     cin>>n;

//     int m;
//     cout<<"Enter the number of edges:"<<endl;
//     cin>>m;
    
//     graph g;

//     for(int i = 0;i<m;i++){
//         int u,v;
//         cin >>u >>v;

//         //creating an undirected graph
//         g.addEdge(u,v,0);
//     }

//     //print graph
//     g.printAdjlist();

// }


#include<iostream>

using namespace std;
#include <vector>
//make graph using template

// #include<bits/stdc++.h>
// using namespace std;
// template <typename T>

// class graph{

//     public:
//     unordered_map<T,list<T>>adj;

//     void addEdge(T u,T v,bool direction){
//         //direction = 0 ->undirected
//         //direction = 1 -> directed graph

//         //create an edge from u to v
//         adj[u].push_back(v);

//         if(direction == 0){
//             //for directed v to u
//             adj[v].push_back(u);
//         }
//     }

//     void printAdjlist(){
//         for(auto i: adj){
//             cout<<i.first<<"->";
//             for(auto j:i.second){
//                 cout<<j<<",";
//             }
//             cout <<endl;
//         }
//     }
// };

int main(){

    int n;
    cout<<"enter ther number of nodes:"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges:"<<endl;
    cin>>m;
    
    

    for(int i = 0;i<m;i++){
        int u,v;
        cin >>u >>v;

        //creating an undirected graph
        // g.addEdge(u,v,0);
    }

    //print graph
    // g.printAdjlist();

}