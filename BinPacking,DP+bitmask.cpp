#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n = 4; // Number of people
    int x = 10; // Maximum weight capacity of the elevator
    vector<int> weight = {4, 8, 6, 2}; // Weights of the people

    // Declare the best array where best[s] = {rides(S), last(S)}
    vector<pair<int, int> > best(1 << n, {n + 1, 0});

    // Base case: Empty set requires 1 ride with 0 weight
    best[0] = {1, 0};

    // Fill the DP table
    for (int s = 1; s < (1 << n); s++) {
        best[s] = {n + 1, 0}; // Initialize with an impossible value (n + 1 rides)
        for (int p = 0; p < n; p++) {
            if (s & (1 << p)) {
                // Get the subset without person p
                auto option = best[s ^ (1 << p)];
                if (option.second + weight[p] <= x) {
                    // Add person p to the existing ride
                    option.second += weight[p];
                } else {
                    // Reserve a new ride for person p
                    option.first++;
                    option.second = weight[p];
                }
                // Update the best result for the subset s
                best[s] = min(best[s], option);
            }
        }
    }

    // The result for the full set {0, 1, ..., n-1} is stored in best[(1 << n) - 1]
    cout << "Minimum number of rides: " << best[(1 << n) - 1].first << endl;

    return 0;
}
