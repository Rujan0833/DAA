/*Theory:
The Knapsack problem is a classic optimization problem that seeks to maximize the value of items selected for inclusion in a
 knapsack, given a limited capacity.

Time Complexity:

    Best Case: O(2n)O(2n) where nn is the number of items. This occurs when the optimal solution is found early during the search.
    Worst Case: O(2n)O(2n) where nn is the number of items. This occurs when all possible combinations need to be considered.
    Average Case: O(2n)O(2n) where nn is the number of items.

Space Complexity:

    O(n)O(n) for recursive stack space due to the backtracking algorithm.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to solve the Knapsack problem using dynamic programming
int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    cout << "Total steps taken to solve the Knapsack problem: " << (val.size() * W) << endl;

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val) << endl;

    return 0;
}
