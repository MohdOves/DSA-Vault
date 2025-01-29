#include<iostream>
#include<deque>
#include<vector>
#include<queue> 
using namespace std;

// Function to find the first negative integer in every window of size K
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long> dq;
    vector<long long> ans;

    // Process first window of size K
    for(long long i = 0; i < K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);  // Store index of negative element
        }
    }

    // Store answer of first K size window
    if(!dq.empty()) {
        ans.push_back(A[dq.front()]);  // First negative number
    } else {
        ans.push_back(0);  // No negative number in the window
    }

    // Process for remaining windows
    for(long long i = K; i < N; i++) {
        // Remove the elements which are out of this window
        if(!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }

        // Add the current element if it is negative
        if(A[i] < 0) {
            dq.push_back(i);
        }

        // Store the answer for this window
        if(!dq.empty()) {
            ans.push_back(A[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    // Example usage of printFirstNegativeInteger
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28}; // Sample array
    long long int N = sizeof(A) / sizeof(A[0]);  // Size of array
    long long int K = 3;  // Window size

    // Finding the first negative number in every window of size K
    vector<long long> result = printFirstNegativeInteger(A, N, K);

    // Display the result
    cout << "First negative numbers in every window of size " << K << " are: ";
    for(long long x : result) {
        cout << x << " ";
    }
    cout << endl;

   
    return 0;
}
