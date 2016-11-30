#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int p[110],h[110],c[110];
int dp[110];
int n,m;

void zeroonepack(int val,int weight){
    for(int i=n;i>=val;i--)
        dp[i]=dp[i]>(dp[i-val]+weight)?dp[i]:(dp[i-val]+weight);
}

void completepack(int val,int weight){
    for(int i=val;i<=n;i++)
        dp[i]=dp[i]>(dp[i-val]+weight)?dp[i]:(dp[i-val]+weight);
}

void multipack(int val,int weight,int count){
    if(val*count>=n){
        completepack(val,weight);
        return ;
    }
    int k=1;
    while(k<count){
        zeroonepack(k*val,k*weight);
        count-=k;
        k*=2;
    }
    zeroonepack(count*val,count*weight);
}

int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&p[i],&h[i],&c[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<m;i++)
            multipack(p[i],h[i],c[i]);
        printf("%d\n",dp[n]);
    }
}