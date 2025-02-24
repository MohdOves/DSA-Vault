#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    // Initialize adjacency list
    vector<vector<int>> adj(n);

    // Fill the adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Add edge u -> v and v -> u (undirected graph)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Format the adjacency list to include the node itself
    vector<vector<int>> formattedAdj(n);
    for (int i = 0; i < n; i++) {
        // Add the node itself
        formattedAdj[i].push_back(i);

        // Add all neighbors
        for (int neighbor : adj[i]) {
            formattedAdj[i].push_back(neighbor);
        }
    }

    return formattedAdj;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adjacencyList = printAdjacency(n, m, edges);

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjacencyList.size(); i++) {
        for (int j = 0; j < adjacencyList[i].size(); j++) {
            cout << adjacencyList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
