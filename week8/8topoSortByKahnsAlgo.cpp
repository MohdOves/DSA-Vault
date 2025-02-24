#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges,int v,int e){
    //creatre adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    //0 indegree walo ko push kardo
    queue<int>q;

    for(int i=0;i<v;i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    //do bfs
    vector<int>ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //ams store
        ans.push_back(front);

        //neighbopur indegree update
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]== 0)
            q.push(neighbour);
        }
    }
    return ans;
    }

int main(){
     int v = 6; // Number of vertices
    int e = 6; // Number of edges

    // Directed edges
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}