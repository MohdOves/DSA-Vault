#include<bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n,vector<pair<int,int>>& edges){
      //creatre adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first-1;
        int v = edges[i].second-1;

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int>indegree(n);
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    //0 indegree walo ko push kardo
    queue<int>q;

    for(int i=0;i<n;i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    //do bfs
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //increase count
        cnt++;

        //neighbopur indegree update
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]== 0)
            q.push(neighbour);
        }
    }
    if(cnt == n){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> edges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    if (detectCycleInDirectedGraph(n, edges)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}