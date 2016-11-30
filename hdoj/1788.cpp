/*
sample input:
2 1
2 3
0 0
 */
#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

int main(){
    ll tmp;
    int n,k;
    // freopen("0input.txt","r",stdin);
    while(scanf("%d%d",&n,&k),n+k){
        ll ans=1;
        for(int i=0;i<n;++i){
            scanf("%I64d",&tmp);
            ans=ans*tmp/gcd(ans,tmp);
        }
        printf("%I64d\n",ans-k);
    }
    return 0;
}