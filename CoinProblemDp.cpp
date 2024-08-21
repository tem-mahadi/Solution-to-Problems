#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first;
#define S second;
#define Y yes;
#define N no;
#define pb push_back;
#define mp make_pair;
#define f(i, a, b) for (int i = a; i < b; i++)
const ll MD = 1e9 + 7;
const ll MX = 1e7 + 10;

void solve(int x, vector<int> &value, vector<int> &First)
{
    if (x < 0)
    {
        cout << "Impossible!!";
        return;
    }
    if (x == 0)
        cout << "No coins needed";
    else
    {
        cout << "Number of coins needed: " << value[x] << endl;
        cout<<"The coins are: ";
        while(x>0){
            cout<<First[x]<<" ";
            x-=First[x];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    cout << "Enter the number of coins: ";
    int n;
    cin >> n;
    cout << "Enter the value of the coins: ";
    vector<int> coins(n);
    f(i, 0, n) cin >> coins[i];
    cout << "Enter the sum you wanna make: ";
    ll money;
    cin >> money;
    vector<int> value(money + 1);
    vector<int> First(money + 1);
    for (int x = 1; x <= money; x++)
    {
        value[x] = MX;
        for (auto c : coins)
        {
            if(x-c<=0) break;
            if (value[x - c] + 1 < value[x])
            {
                value[x] = value[x - c] + 1;
                First[x] = c;
            }
        }
    }
    while (tc--)
        solve(money, value, First);
    return 0;
}