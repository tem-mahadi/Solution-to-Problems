#include<iostream>
using namespace std;

int main(){
    float a;
    cin>>a;
    if(a-int(a)) 
    cout<<"float "<<int(a)<<" "<<a-int(a);
    else 
    cout<<"int "<<(int)a;
    return 0;
}