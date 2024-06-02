#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int& total_steps) {
    total_steps = 0;
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            total_steps++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        total_steps += 3;  // Steps for swapping
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total_steps;
    selectionSort(arr, n, total_steps);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total steps required: " << total_steps << endl;

    return 0;
}