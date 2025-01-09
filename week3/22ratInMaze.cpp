#include<iostream>
#include<vector>
#include<algorithm>  // For sorting
using namespace std;

// Check if it's safe to move to the cell (x, y)
bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    return false;
}

// Recursive function to explore all paths
void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {

    // you have reach x,y here

    // Base case: reached destination
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    //4 choices - D,R,L,U

    // Moving down (D)
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();  // Backtrack
    }

    // Moving left (L)
    newx = x; 
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();  // Backtrack
    }

    // Moving right (R)
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();  // Backtrack
    }

    // Moving up (U)
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();  // Backtrack
    }

    // Unmark the cell (backtrack)
    visited[x][y] = 0;
}

// Function to find all paths in the maze
vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;

    // If the starting point is blocked, no paths can be found
    if (m[0][0] == 0) {
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = m;
    //intilization with 0
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            visited[i][j] = 0;
        }
    }
    
    
    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);  // Start from (0, 0)

    sort(ans.begin(), ans.end());  // Sort paths lexicographically (optional)
    return ans;
}

int main() {
    // Example usage
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = maze.size();
    vector<string> result = findPath(maze, n);

    // Print the resulting paths
    for (string path : result) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
