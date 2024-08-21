#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to calculate the edit distance between strings x and y
int editDistance(const string& x, const string& y) {
    int n = x.length();
    int m = y.length();

    // Create a 2D array to store the distances
    vector<vector<int> > dp(n + 1, vector<int>(m + 1));

    // Initialize the base cases
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i; // If y is empty, remove all characters from x
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j; // If x is empty, insert all characters from y
    }

    // Fill the dp array using the recurrence relation
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (x[i - 1] == y[j - 1]) ? 0 : 1;
            dp[i][j] = min(dp[i][j - 1] + 1,      // Insert
                            dp[i - 1][j] + 1,      // Remove
                            dp[i - 1][j - 1] + cost); // Match/Modify
        }
    }

    // The edit distance is the value in the bottom-right corner of the matrix
    return dp[n][m];
}

int main() {
    string x = "kitten";
    string y = "sitting";

    cout << "Edit Distance between \"" << x << "\" and \"" << y << "\": " << editDistance(x, y) << endl;

    return 0;
}
