#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int k = 3; // Number of products
    int n = 3; // Number of days

    vector<vector<int> > price = {
        {1, 50, 50},
        {50, 3, 50},
        {50, 50, 2}
    };

    // Initialize the DP table with large values
    vector<vector<int> > total(1 << k, vector<int>(n, INT_MAX));

    // Base case: Buy one product on the first day
    for (int x = 0; x < k; x++) {
        total[1 << x][0] = price[x][0];
    }

    // Fill the DP table for days d > 0
    for (int d = 1; d < n; d++) {
        for (int S = 0; S < (1 << k); S++) {
            total[S][d] = total[S][d-1]; // Case 1: No purchase on day d
            for (int x = 0; x < k; x++) {
                if (S & (1 << x)) { // If product x is in subset S
                    total[S][d] = min(total[S][d], total[S ^ (1 << x)][d-1] + price[x][d]);
                }
            }
        }
    }

    // Final answer
    int answer = total[(1 << k) - 1][n-1];
    cout << "Minimum total price: " << answer << endl;

    return 0;
}
