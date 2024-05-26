#include <iostream>
#include <vector>

using namespace std;

vector<long long> fibonacci(int n, int &steps) {
    steps = 0; // Initialize step counter
    vector<long long> series(n);

    if (n > 0) {
        series[0] = 0;
        ++steps; // One step for initialization
    }
    if (n > 1) {
        series[1] = 1;
        ++steps; // One step for initialization
    }

    for (int i = 2; i < n; ++i) {
        series[i] = series[i - 1] + series[i - 2];
        ++steps; // Increment step counter for each addition
    }

    return series;
}

int main() {
    int n, steps;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    vector<long long> series = fibonacci(n, steps);

    cout << "Fibonacci series up to " << n << " terms: ";
    for (int i = 0; i < n; ++i) {
        cout << series[i] << " ";
    }
    cout << endl;

    cout << "Total steps to compute the Fibonacci series: " << steps << endl;

    return 0;
}
