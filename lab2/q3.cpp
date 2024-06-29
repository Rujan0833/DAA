//MINIMAX ALGORITHM

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void findMinAndMax(const vector<int>& arr, int& min_val, int& max_val, int& steps) {
    // Initialize the min and max values
    min_val = INT_MAX;
    max_val = INT_MIN;
    steps = 0;

    // Loop through the array to find min and max values
    for (int val : arr) {
        if (val < min_val) {
            min_val = val;
        }
        if (val > max_val) {
            max_val = val;
        }
        steps += 2; // Each comparison counts as a step
    }
}

int main() {
    vector<int> arr = {3, 5, 1, 8, 7, 2, 6};
    int min_val, max_val, steps;

    findMinAndMax(arr, min_val, max_val, steps);

    cout << "Minimum value: " << min_val << endl;
    cout << "Maximum value: " << max_val << endl;
    cout << "Total steps: " << steps << endl;

    return 0;
}

