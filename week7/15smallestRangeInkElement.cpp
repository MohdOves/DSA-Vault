#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>>& a, int k, int n) {
    int mini = INT32_MAX;
    int maxi = INT32_MIN;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < k; i++) {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    while (!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        if (temp->col + 1 < n) {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        } else {
            break;
        }

        delete temp;  // Freeing the dynamically allocated memory
    }
    return (end - start + 1);
}

int main() {
    vector<vector<int>> a = {
        {1, 3, 5},
        {2, 6, 8},
        {0, 9, 10}
    };

    int k = a.size();     // Number of rows
    int n = a[0].size();  // Number of columns

    int range = kSorted(a, k, n);
    cout << "The smallest range is: " << range << endl;

    return 0;
}
