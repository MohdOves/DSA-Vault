#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s]; // Select the first element as the pivot
    int cnt = 0;

    // Count elements smaller or equal to the pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }

    // Place pivot at the correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // Re-arrange elements to make left side smaller and right side larger than the pivot
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot && i < pivotIndex) {
            i++;
        }
        while (arr[j] > pivot && j > pivotIndex) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    // Base case: if the segment has 0 or 1 element, it's already sorted
    if (s >= e) {
        return;
    }

    // Partition the array and get the pivot index
    int p = partition(arr, s, e);

    // Recursively sort elements before and after the partition
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[5] = {2, 4, 1, 6, 9};
    int n = 5;

    // Perform quicksort
    quickSort(arr, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
 