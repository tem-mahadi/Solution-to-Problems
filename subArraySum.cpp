#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
#include<cmath>
#include<string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first;
#define S second;
#define Y yes;
#define N no;
#define pb push_back;
#define mp make_pair;
#define f(i,a,b) for(int i=a; i<b; i++)
const ll MD = 1e9 + 7;
const ll MX = 1e7 + 10;

void solve() {
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int sum = 0; // example sum to find
    int n = arr.size();
    
    int left = 0, right = 0;
    int tempSum = 0;
    bool flag = false;

    while (right < n) {
        tempSum += arr[right];

        if (tempSum == sum) {
            flag = true;
            break;
        }

        while (tempSum > sum && left <= right) {
            tempSum -= arr[left];
            left++;
        }


        right++;
    }

    if (flag)
        cout << "Start: " << left + 1 << " End: " << right + 1 << endl;
    else
        cout << "Impossible" << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
