#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int count=0;
    while(next_permutation(s.begin(),s.end())){
        cout<<s<<endl;
        count++;
    }
    cout<<count;
    return 0;
}