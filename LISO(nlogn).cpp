#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    vector<int> tails;

    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }

    return tails.size();
}

int main() {
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(4);
    nums.push_back(8);

    cout << "Length of LIS: " << lengthOfLIS(nums) << endl;
    return 0;
}
