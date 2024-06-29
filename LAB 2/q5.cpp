//Quicksort

#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high, int& steps) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            steps += 3; // Count each comparison and swap
        }
        steps++; // Count each comparison
    }

    swap(arr[i + 1], arr[high]);
    steps += 3; // Count the final swap
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high, int& steps) {
    if (low < high) {
        int pi = partition(arr, low, high, steps);

        quickSort(arr, low, pi - 1, steps);  // Sort elements before partition
        quickSort(arr, pi + 1, high, steps); // Sort elements after partition
    }
}

// Function to print the elements of the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int steps = 0;

    quickSort(arr, 0, arr.size() - 1, steps);

    cout << "Sorted array: ";
    printArray(arr);

    cout << "Total steps: " << steps << endl;

    return 0;
}
