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
    int n; cout<<"Number of Elements: "; cin>>n;
    vi seq(n),length(n);
    f(i,0,n){
        cin>>seq[i];
    }
    f(i,0,n){
        length[i]=1;
        f(j,0,i){
            if(seq[j]<seq[i]) length[i]=max(length[i],length[j]+1);
        }
    }
    int maxseq=0;
    f(i,0,n) maxseq=max(length[i],maxseq);
    cout<<"Highest increasing subsequence: "<<maxseq;
    }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}