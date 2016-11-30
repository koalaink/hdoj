#include<iostream>
#include<stdio.h>
using namespace std;

int e,f;
int dp[10010];
int p[501],w[501];
int n;

void completepack(int price,int weight){
    for(int i=weight;i<=f;i++)
        if(dp[i]>dp[i-weight]+price)
            dp[i]=dp[i-weight]+price;
}

int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&e,&f);
        f=f-e;
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d%d",&p[i],&w[i]);
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(i=0;i<n;i++)
            completepack(p[i],w[i]);
        if(dp[f]<0x3f3f3f3f) printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f]);
        else printf("This is impossible.\n");
    }
}