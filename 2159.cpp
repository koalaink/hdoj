#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int val[105][2];
int dp[105][105];

int main(){
    int n,m,k,s,i,j,l,flag;
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
        for(i=1;i<=k;i++){
            scanf("%d%d",&val[i][0],&val[i][1]);
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<=m;i++){
            for(j=1;j<=s;j++)
                for(l=1;l<=k;l++)
                    if(i>=val[l][1]) dp[i][j]=max(dp[i][j],dp[i-val[l][1]][j-1]+val[l][0]);
            if(dp[i][s]>=n) break;
        }
        printf("%d\n",m-i);
    }
    return 0;
}