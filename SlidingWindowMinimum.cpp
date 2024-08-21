#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> slidingWindowMinimum(const vector<int>& arr, int k) {
    deque<int> dq;  // Deque to store indices of elements
    vector<int> result;  // Result array to store the minimums
    
    for (int i = 0; i < arr.size(); i++) {
        // Remove elements from the front if they are out of this window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove elements from the back if they are greater than or equal to the current element
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }
        
        // Add the current element's index to the deque
        dq.push_back(i);
        
        // The front of the deque is the minimum of the current window
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;  // Window size
    
    vector<int> result = slidingWindowMinimum(arr, k);
    
    cout << "Sliding Window Minimums: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}