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

void solve(int &x) {
    cout<<"Number of permutations for the sum: "<<x<<endl;
    }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    cout<<"Enter number of coins: "; int n; cin>>n;
    cout<<"Enter the coins: "; vi coins(n); f(i,0,n) cin>>coins[i];
    cout<<"Enter the sum you wanna make: "; int money; cin>>money;
    vi permutations(money+1);
    permutations[0]=permutations[1]=1;
    f(i,2,money+1){
        for(auto c: coins){
            if(i-c<0) break;
            permutations[i]+=permutations[i-c];
            permutations[i]%=MD;
        }
    }
    while(tc--) solve(permutations[money]);
    return 0;
}