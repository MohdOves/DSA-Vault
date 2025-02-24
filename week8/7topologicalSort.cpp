#include<bits/stdc++.h>
using namespace std;

void topoSort(int node,vector<bool>& visited,stack<int>& s,unordered_map<int,list<int>>& adj){
    visited[node]= 1;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour])
            topoSort(neighbour,visited,s,adj);
    }

    //important
    s.push(node);
}

vector<int> topological(vector<vector<int>>& edges, int v, int e){
    //create adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //call dfs topological util function for all component
    vector<bool> visited(v);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }
    vector<int>ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){
     int v = 6; // Number of vertices
    int e = 6; // Number of edges
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = topological(edges, v, e);

    cout << "Topological Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
    
}