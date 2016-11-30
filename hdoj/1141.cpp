#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
    __int64 n,i;
    double ans;
    while(cin>>n,n){
        n=(n-1960)/10+2;
        n=1<<n;
        ans=0;
        i=0;
        while(ans<n)
            ans+=log((double)++i)/log((double)2);
        cout<<i-1<<endl;
    }
}
