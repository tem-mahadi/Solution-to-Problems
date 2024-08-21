#include <iostream>
#include <bitset>

void printSubsetsWithKElements(int n, int k) {
    for (int b = 0; b < (1 << n); b++) {
        if (__builtin_popcount(b) == k) {
            // Print the subset
            std::cout << "Subset: ";
            for (int i = 0; i < n; i++) {
                if (b & (1 << i)) { // Check if the ith element is in the subset
                    std::cout << (i + 1) << " "; // Convert 0-based index to 1-based
                }
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int n = 4; // Number of elements in the set
    int k = 2; // We want subsets with exactly 2 elements

    printSubsetsWithKElements(n, k);

    return 0;
}
