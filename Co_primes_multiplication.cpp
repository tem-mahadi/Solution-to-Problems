#include<iostream>
#include<cmath>
using namespace std;
 int prime(int x){
    int flag=1;
    if(x==2 || x==3) flag=1;
    else {
        for (int i =2; i <= sqrt(x) ; i++) {
            if(x%i==0) {
                flag=0; 
                break;
            }
        }
    }
    if(flag) return 1;
    else return 0;
}
 int main(){
    int n;
    cin>>n;
     for (int i = 2; n!=1 ; i++) {
        while(prime(i)){
            if(n%i==0) {
                if(n==i) cout<<i<<endl;
                else cout<<i<<" * ";
                n/=i;
            }
            else break;
        }
    }
    return 0;
}