#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
#include<cmath>
#include<string>

using namespace std;

string smallestWindow(string s, string p) {
    int len1 = s.length();
    int len2 = p.length();

    // Check if string's length is less than P's length
    if (len1 < len2) return "-1";

    // Initialize hash arrays for P and string S
    vector<int> hashP(256, 0);
    vector<int> hashS(256, 0);

    // Store occurrence of characters of P
    for (int i = 0; i < len2; i++) hashP[p[i]]++;

    int start = 0, start_idx = -1, min_len = INT_MAX;
    // Count of characters matched
    int count = 0;

    // Start traversing the string
    for (int j = 0; j < len1; j++) {
        // Count occurrence of characters of string S
        hashS[s[j]]++;

        // If S's char matches with P's char, increment count
        if (hashP[s[j]] != 0 && hashS[s[j]] <= hashP[s[j]]) {
            count++;
        }

        // If all characters are matched
        if (count == len2) {
            // Try to minimize the window
            while (hashS[s[start]] > hashP[s[start]]
                   || hashP[s[start]] == 0) {
                if (hashS[s[start]] > hashP[s[start]]) {
                    hashS[s[start]]--;
                }
                start++;
            }

            // Update window size
            int len = j - start + 1;
            if (min_len > len) {
                min_len = len;
                start_idx = start;
            }
        }
    }
    // If no window found
    if (start_idx == -1) return "-1";

    // Return the substring starting from start_idx
    // and length min_len
    return s.substr(start_idx, min_len);
}

int main() {
    string s = "timetopractoctice";
    string p = "toc";

    string result = smallestWindow(s, p);
    cout << result;

    return 0;
}
