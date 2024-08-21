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
#define f(i,a,b) for(int i=a; i<=b; i++)

const ll MD = 1e9 + 7;
const ll MX = 1e7 + 10;

void solve() {
    cout<<"Enter the set__ How many items: ";
    int n; cin>>n;
    cout<<"Enter the items__ ";
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    cout<<"Sum to make: ";
    ll x; cin>>x;
    vector<ll> sumset;
    for (int i = 0; i < (1<<n); i++)
    {
        ll sum=0;
        for (int j = 0; j < n; j++)
        {
        if(i & (1<<j)) sum+=s[j];
        }
        sumset.push_back(sum);
    }
    // for(int c: sumset)
    // cout<<c<<" ";
    if(find(sumset.begin(),sumset.end(),x) != sumset.end())
    cout<<"Its Possible\n";
    else cout<<"Its Not Possible\n";
    }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}