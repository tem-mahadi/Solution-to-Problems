#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define f(i,a,b) for(int i=a; i<b; i++)
const ll MD = 1e9 + 7;
const ll MX = 1e7 + 10;

void solve() {
    int arr[8] = {15, 2, 4, 8, 9, 5, 10, 23};
    sort(arr, arr + 8);
    int sum; cin>>sum;
    
    // Iterate through each pair of elements
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 7; j++) {
            int tempSum = arr[i] + arr[j];
            // Check if the required third element exists using binary search
            if (binary_search(arr + j + 1, arr + 8, sum - tempSum)) {
                cout << arr[i] << " + " << arr[j] << " + " << sum - tempSum << " = " << sum << endl;
                return;
            }
        }
    }
    
    cout << "Impossible!" << endl;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm> // for std::sort

// bool find3Sum(std::vector<int>& arr, int x) {
//     int n = arr.size();
    
//     // Sort the array
//     std::sort(arr.begin(), arr.end());
    
//     // Iterate through the array
//     for (int i = 0; i < n - 2; i++) {
//         // Two pointers
//         int left = i + 1;
//         int right = n - 1;
        
//         while (left < right) {
//             int sum = arr[i] + arr[left] + arr[right];
            
//             if (sum == x) {
//                 std::cout << "Triplet found: " << arr[i] << ", " << arr[left] << ", " << arr[right] << std::endl;
//                 return true;
//             } else if (sum < x) {
//                 left++;
//             } else {
//                 right--;
//             }
//         }
//     }
    
//     std::cout << "No triplet found that sums to " << x << std::endl;
//     return false;
// }

// int main() {
//     std::vector<int> arr = {12, 3, 4, 1, 6, 9};
//     int x = 24;
    
//     find3Sum(arr, x);
    
//     return 0;
// }

