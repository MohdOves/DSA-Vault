#include<bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited,unordered_map<int,list<int>>&adj ){
    visited[node] = true;
    dfsVisited[node]= true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour,visited,dfsVisited,adj);
            if(cycleDetected){
                return true;
            }
            else if(dfsVisited[neighbour]){
                //visited true
                return true;
            }
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectInDirectedGraph(int n,vector<pair<int,int>>& edges){
    //create a adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    //call dfs for all component
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cycleFound = checkCycleDFS(i,visited,dfsVisited,adj);
            if(cycleFound)
                return  true;
        }
    }
    return false;
}

int main(){
    int n = 4; // Number of nodes
    vector<pair<int, int>> edges = {
        {1, 2}, {2, 3}, {3, 4}, {4, 2} // A cycle exists: 2 -> 3 -> 4 -> 2
    };

    if (detectInDirectedGraph(n, edges)) {
        cout << "Cycle Detected\n";
    } else {
        cout << "No Cycle Detected\n";
    }
}