#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of subgrids with all black corners
int countBlackCornersSubgrids(vector<vector<int> >& grid, int n, int N) {
    vector<vector<int> > color(n, vector<int>(n / N + 1, 0));

    // Convert each row into a list of N-bit numbers
    for (int y = 0; y < n; y++) {
        for (int k = 0; k < n; k++) {
            if (grid[y][k] == 1) {
                color[y][k / N] |= (1 << (k % N));
            }
        }
    }

    int totalCount = 0;

    // Iterate through all pairs of rows
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int count = 0;

            // Count common bits (1s) in blocks of N columns
            for (int i = 0; i <= n / N; i++) {
                count += __builtin_popcount(color[a][i] & color[b][i]);
            }

            // Add the number of subgrids formed by this pair of rows
            totalCount += count * (count - 1) / 2;
        }
    }

    return totalCount;
}

int main() {
    int n = 4; // Grid size
    int N = 2; // Block size

    // Example grid
    vector<vector<int> > grid = {
        {1, 0, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {0, 1, 1, 1}
    };

    int result = countBlackCornersSubgrids(grid, n, N);
    cout << "Number of subgrids with all black corners: " << result << endl;

    return 0;
}


int count_subgrids(const int** color, int n)
{
    int subgrids = 0;
    for(int a=0; a<n; ++a)
        for(int b=a+1; b<n; ++b) {    // loop over pairs (a,b) of rows 
            int count=0;
            for(int i=0; i<n; ++i) {  // loop over all columns
                if(color[a][i]==1 && color[b][i]==1)
                    ++count;
            }
            subgrids += ((count-1)*count)/2;
        }
    return subgrids;
}