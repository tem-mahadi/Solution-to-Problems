#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform First-Fit Decreasing bin packing
int firstFitDecreasing(vector<int>& items, int binCapacity) {
    // Sort the items in decreasing order
    sort(items.rbegin(), items.rend());
    
    // Vector to store remaining capacity of bins
    vector<int> bins;

    // Iterate over each item
    for (int &item : items) {
        bool placed = false;

        // Try to place the item in the first bin that can accommodate it
        for (int &bin : bins) {
            if (bin >= item) {
                bin -= item;
                placed = true;
                break;
            }
        }

        // If the item doesn't fit in any bin, start a new bin
        if (!placed) {
            bins.push_back(binCapacity - item);
        }
    }

    // The number of bins used is the size of the bins vector
    return bins.size();
}

int main() {
    // Example items and bin capacity
    vector<int> items = {4, 8, 1, 4, 2, 1};
    int binCapacity = 10;

    // Calculate the minimum number of bins needed
    int numBins = firstFitDecreasing(items, binCapacity);

    cout << "Minimum number of bins required: " << numBins << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // Structure to represent an item
// struct Item {
//     int weight;
//     int id; // Optional: For tracking item identities
// };

// // Function to perform First Fit Decreasing (FFD) bin packing algorithm
// int firstFitDecreasing(vector<Item>& items, int binCapacity) {
//     // Sort items in descending order of weight
//     sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
//         return a.weight > b.weight;
//     });

//     // Initialize bins
//     vector<int> bins;
//     bins.push_back(0); // First bin is empty

//     // Place each item in a bin
//     for (const Item& item : items) {
//         bool placed = false;
//         for (int i = 0; i < bins.size(); ++i) {
//             // Check if item fits in current bin
//             if (bins[i] + item.weight <= binCapacity) {
//                 bins[i] += item.weight;
//                 placed = true;
//                 break;
//             }
//         }
//         // If item doesn't fit in any existing bin, create a new bin
//         if (!placed) {
//             bins.push_back(item.weight);
//         }
//     }

//     // Return the number of bins used
//     return bins.size();
// }

// int main() {
//     // Example usage
//     vector<Item> items = {
//         {10, 1}, {5, 2}, {12, 3}, {7, 4}, {8, 5}, {6, 6}
//     };
//     int binCapacity = 15;

//     int numBins = firstFitDecreasing(items, binCapacity);

//     cout << "Number of bins required: " << numBins << endl;

//     return 0;
// }
