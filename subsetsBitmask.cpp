#include <iostream>
#include <bitset>

void printSubsets(int x) {
    std::cout << "Set: " << std::bitset<8>(x) << "\n";
    std::cout << "Subsets:\n";
    
    int b = 0; // Start with the empty subset
    do {
        // Print the current subset
        std::cout << std::bitset<8>(b) << "\n";
        
        // Generate the next subset
    } while (b = (b - x) & x);
    //When you subtract x from b, it's a bitwise subtraction.
    //The important thing is that when b < x, the result will wrap around, 
    //flipping some bits from 0 to 1.
    //The result of (b - x) is then bitwise ANDed with x. 
    //This ensures that any bits that were outside of the original set x are turned off, 
    //i.e., the result will still be a subset of x.
}

int main() {
    int x = 0b1011; // Example set {1, 2, 8} represented by the bitmask 0b1011 (binary for 11)

    printSubsets(x);

    return 0;
}
