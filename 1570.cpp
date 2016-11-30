/*
sample input:
2
C 4 2
A 10 10
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

long long jc(int n){
    long long ans=1;
    while(n){
        ans*=n;
        --n;
    }
    return ans;
}

long long a(int n,int m){
    return jc(n)/jc(n-m);
}

long long c(int n,int m){
    return a(n,m)/a(m,m);
}

int main(){
    // freopen("0input.txt","r",stdin);
    int t,n,m;
    char ch;
    scanf("%d",&t);
    while(t--){
        getchar();scanf("%c %d %d",&ch,&n,&m);
        if(ch=='A') printf("%I64d\n",a(n,m));
        else if(ch=='C') printf("%I64d\n",c(n,m));
    }
    return 0;
}