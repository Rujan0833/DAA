//MERGE SORT

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, int& steps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        steps++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        steps++;
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        steps += 2;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        steps++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        steps++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, int& steps) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, steps);
    mergeSort(arr, mid + 1, right, steps);

    merge(arr, left, mid, right, steps);
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int steps = 0;

    mergeSort(arr, 0, arr.size() - 1, steps);

    cout << "Sorted array: ";
    printArray(arr);

    cout << "Total steps: " << steps << endl;

    return 0;
}
