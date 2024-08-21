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
    cout<<"Enter the number of tasks: ";
    int n; cin>>n;
    vector<pair<pair<int,int>,string> > tasks(n);
    f(i,0,n) {
        tasks[i].second=i+65;
        cout<<"Task "<<tasks[i].second<<endl;
        cout<<"Duration: "; cin>>tasks[i].first.first;
        cout<<" Deadline: "; cin>>tasks[i].first.second;
    }
    sort(tasks.begin(),tasks.end());
    int points=0,time=0;
    cout<<"Scheduled tasks: ";
    f(i,0,n){
        cout<<" >> "<<tasks[i].second;
        points+= (tasks[i].first.second-tasks[i].first.first-time);
        time+=tasks[i].first.first;
    }
    cout<<"\nPoints received: "<<points<<endl;
    }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}