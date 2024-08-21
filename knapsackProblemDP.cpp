#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int> > dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50; // Capacity of the knapsack
    vector<int> weights = {10, 20, 30}; // Weights of the items
    vector<int> values = {60, 100, 120}; // Values of the items
    int n = weights.size(); // Number of items

    cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int main() {
//     int n = 4; // Number of people
//     int x = 10; // Maximum weight capacity of the elevator
//     vector<int> weights = {4, 8, 6, 2}; // Weights of the people

//     // Initialize DP arrays
//     vector<int> dp(1 << n, INT_MAX); // dp[mask] represents the minimum number of rides needed for subset mask
//     vector<int> currentWeight(1 << n, 0); // currentWeight[mask] stores the current weight in the last ride

//     // Base case
//     dp[0] = 1;
//     currentWeight[0] = 0;

//     // Fill the DP table
//     for (int mask = 1; mask < (1 << n); mask++) {
//         for (int i = 0; i < n; i++) {
//             if (mask & (1 << i)) {
//                 int prevMask = mask ^ (1 << i);
//                 if (currentWeight[prevMask] + weights[i] <= x) {
//                     if (dp[prevMask] < dp[mask]) {
//                         dp[mask] = dp[prevMask];
//                         currentWeight[mask] = currentWeight[prevMask] + weights[i];
//                     }
//                 } else {
//                     if (dp[prevMask] + 1 < dp[mask]) {
//                         dp[mask] = dp[prevMask] + 1;
//                         currentWeight[mask] = weights[i];
//                     }
//                 }
//             }
//         }
//     }

//     // Final answer: the minimum number of rides for all people
//     cout << "Minimum number of rides: " << dp[(1 << n) - 1] << endl;

//     return 0;
// }

