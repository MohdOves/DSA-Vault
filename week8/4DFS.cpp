#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int,bool>& visited,unordered_map<int,list<int>>adj,vector<int>& component){
    
    //ans store
    component.push_back(node);
    
    //mark visited
    visited[node] = true;

    //every connected node k liye recursive call
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }
}

vector<vector<int>> DFS(int V, int E,vector<vector<int>> & edges){

    //prepare ADJlist
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>>ans;
    unordered_map<int,bool>visited;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> components = DFS(V, E, edges);

    cout << "Connected Components:" << endl;
    for (auto component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}