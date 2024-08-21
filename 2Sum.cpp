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
    int arr[8]={15, 2, 4, 8, 9, 5, 10, 23};
    sort(arr,arr+8);
    int sum=18;
    int left=0; int right=7; int tempSum;
    while(left<=right){
        tempSum=arr[left]+arr[right];
        if(sum==tempSum) break;
        if(tempSum>sum) right--;
        else left++;
    }
    cout<<arr[left]<<" + "<<arr[right]<<" = "<<sum;
    }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
    return 0;
}