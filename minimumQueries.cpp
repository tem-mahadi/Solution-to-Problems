#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class SparseTable {
    vector<vector<int> > st;
    vector<int> log_table;
    int n;

public:
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        int max_log = log2(n) + 1;
        st.assign(n, vector<int>(max_log));
        log_table.resize(n + 1);

        // Precompute log_table values
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }

        // Initialize Sparse Table for intervals of length 1
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        // Build the Sparse Table
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int j = log_table[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11, 3, 5, 7, 12, 6, 4};

    SparseTable st(arr);

    // Queries
    cout << "Minimum in range [0, 5]: " << st.query(0, 5) << endl; // Output: 1
    cout << "Minimum in range [2, 4]: " << st.query(2, 4) << endl; // Output: 2
    cout << "Minimum in range [3, 8]: " << st.query(3, 8) << endl; // Output: 3
    cout << "Minimum in range [7, 10]: " << st.query(7, 10) << endl; // Output: 5

    return 0;
}
