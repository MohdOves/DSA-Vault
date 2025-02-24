//BY BFS

// #include<bits/stdc++.h>
// using namespace std;

// bool isCycleBFS(int src,unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj){
//     unordered_map<int,int>parent;

//     parent[src]= -1;
//     visited[src] = 1;
//     queue<int>q;
//     q.push(src);

//     while(!q.empty()){
//         int front = q.front();
//         q.pop();

//         for(auto neighbour: adj[front]){
//             if(visited[neighbour] == true && neighbour != parent[front]){
//                 return true;
//             }
//             else if(!visited[neighbour]){
//                 q.push(neighbour);
//                 visited[neighbour] = 1;
//                 parent[neighbour] = front;
//             }
//         }
//     }
//     return false;
// }

// string cycleDetection(vector<vector<int>>edges,int n,int m){

//     //create adjacency list
//     unordered_map<int,list<int>>adj;
//     for(int i=0;i<m;i++){
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     //to handle disconnected component
//     unordered_map<int,bool>visited;
//     for(int i=0;i<n;i++){
//         if(!visited[i]){
//             bool ans = isCycleBFS(i,visited,adj);
//             if(ans == 1)
//                 return "Yes";
//         }
//     }
//     return "No";
// }

// int main(){
//     int n = 5; 
//     int m = 5; 
//     vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}};

//     cout << "Cycle Detected: " << cycleDetection(edges, n, m) << endl;

//     return 0;
// }

//BY DFS


#include<bits/stdc++.h>
using namespace std;

bool isCycleDFS(int node,int parent,unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj){

    visited[node]= true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
           bool cycleDetected = isCycleDFS(neighbour,node,visited,adj);
           if(cycleDetected){
                return true;
           }
           else if(neighbour != parent){
                //cycle present
                return true;
           }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>edges,int n,int m){

    //create adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handle disconnected component
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCycleDFS(i,-1,visited,adj);
            if(ans == 1)
                return "Yes";
        }
    }
    return "No";
}

int main(){
    int n = 5; 
    int m = 5; 
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}};

    cout << "Cycle Detected: " << cycleDetection(edges, n, m) << endl;

    return 0;
}