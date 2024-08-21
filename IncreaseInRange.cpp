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
#define F first
#define S second
#define Y yes
#define N no
#define pb push_back;
#define mp make_pair;
#define f(i,a,b) for(int i=a; i<b; i++)
const ll MD = 1e9 + 7;
const ll MX = 1e7 + 10;

void solve() {
    vector<int> v= {1,3,5,6,7,8,4};
    vector<int> diff(7);
    diff[0]=v[0];
    f(i,1,7) diff[i]= v[i]-v[i-1];
    int incr= 5;
    //range 3 to 5
    diff[2]+=5; diff[5]-=5;
    cout<<diff[0]<<" ";
    f(i,1,7) {diff[i]+=diff[i-1]; cout<< diff[i]<<" ";}
    }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}