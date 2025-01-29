#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    private:
    // Function to find the next smaller element's index
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--) {
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
    vector<int> prevSmallerElement(vector<int> arr, int n) {
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

    public:
    // Function to calculate the largest rectangle area in the histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        // Get the next and previous smaller elements' indices
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
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution sol;
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;

    return 0;
}
