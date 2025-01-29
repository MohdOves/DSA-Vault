#include<iostream>
#include<stack>
#include<vector>
using namespace std;

#define MAX 1000 // Define a maximum size for the matrix

class Solution {
    private:
    // Function to find the next smaller element's index
    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top(); // Store index of next smaller element
            s.push(i);
        }
        return ans;
    }

    // Function to find the previous smaller element's index
    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) { // Left to right traversal
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top(); // Store index of previous smaller element
            s.push(i);
        }
        return ans;
    }

    // Function to calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights, int n) {
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = 0;
        for(int i = 0; i < n; i++) {
            int l = heights[i]; // Height of the rectangle
            
            // If no smaller element is found on the right, treat it as beyond the last index
            if(next[i] == -1) {
                next[i] = n;
            }

            // Calculate width of the rectangle
            int b = next[i] - prev[i] - 1;

            // Calculate area and update max area
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

    public:
    // Function to find the maximum rectangular area of 1s in a binary matrix
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Compute area for the first row
        vector<int> heights(m);
        for(int j = 0; j < m; j++) {
            heights[j] = M[0][j];
        }

        int area = largestRectangleArea(heights, m);

        // Update the heights for subsequent rows
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Update the current row's heights based on the previous row
                if(M[i][j] != 0) {
                    heights[j] += M[i][j];
                } else {
                    heights[j] = 0;
                }
            }

            // Calculate the area for the updated row
            area = max(area, largestRectangleArea(heights, m));
        }

        return area;
    }
};

int main() {
    Solution sol;
    int n = 4, m = 4;
    int M[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    cout << "Maximum rectangular area of 1s: " << sol.maxArea(M, n, m) << endl;
    return 0;
}
