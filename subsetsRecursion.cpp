#include <iostream>
#include <vector>

using namespace std;

int n; // The size of the set
vector<int> subset; // To store the current subset

void processSubset(const vector<int>& subset) {
    // Function to process each subset (e.g., print the subset)
    cout << "{ ";
    for (int i : subset) {
        cout << i << " ";
    }
    cout << "}" << endl;
}

void search(int k) {
    if (k == n) {
        // Process the subset when k equals n
        processSubset(subset);
    } else {
        // Do not include k in the current subset
        search(k + 1);
        
        // Include k in the current subset
        subset.push_back(k);
        search(k + 1);
        
        // Backtrack to remove k from the current subset
        subset.pop_back();
    }
}

int main() {
    cout << "Enter the value of n: ";
    cin >> n;
    
    // Start the search from the 0th element
    search(0);
    
    return 0;
}
