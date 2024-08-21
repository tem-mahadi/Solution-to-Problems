#include<iostream>
using namespace std;

bool is_palindrome(string s){
    if(equal(s.begin(),s.end(),s.rbegin()))
    return true;
    else return false;
}

int main(){
    string s;
    cin>>s;
    if(is_palindrome(s)) cout<<s<<" is palindromic";
    else cout<<s<<" is not palindromic";
    return 0;
}