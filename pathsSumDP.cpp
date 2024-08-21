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
    int row,col;
    cout<<"Row= "; cin>>row; cout<<"Col= "; cin>>col;
    int grid[row+1][col+1];
    f(r,1,row+1){
        f(c,1,col+1) cin>>grid[r][c];
    }
    int sum[row+1][col+1];
    f(r,0,row+1){f(c,0,col+1) sum[r][c]=0;}
    f(r,1,row+1){
        f(c,1,col+1){
        sum[r][c]= max(sum[r-1][c],sum[r][c-1])+grid[r][c];
        cout<<sum[r][c]<<" ";}
        cout<<endl;
         }
    
    cout<<"Max sum in row= "; cin>>row; cout<<"col= "; cin>>col;
    cout<<sum[row][col];
    }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}