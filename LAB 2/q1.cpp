#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int& total_steps) {
    total_steps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            total_steps++;
        }

        arr[j + 1] = key;
        total_steps++;
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
    insertionSort(arr, n, total_steps);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total steps required: " << total_steps << endl;

    return 0;
}