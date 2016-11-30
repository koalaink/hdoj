/*
sample input:
2
5 3
83 86 77
15 93 35
86 92 49
3 3 3 1 2
10 5
36 11 68 67 29
82 30 62 23 67
35 29 2 22 58
69 67 93 56 11
42 29 73 21 19
-1 -1 5 -1 4 -1 -1 -1 4 -1
 */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <cmath>
#define MAXM 105
#define MAXN 55
using namespace std;

int m,n,ans;
int dp[MAXM][MAXN];
int matrix[MAXN][MAXN];

int main(){
    // freopen("0input.txt","r",stdin);
    int t,i,j,k,tmp;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(i=1;i<=n;++i) for(j=1;j<=n;++j)
            scanf("%d",&matrix[i][j]);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;++i){
            scanf("%d",&tmp);
            if(tmp==-1){
                for(j=1;j<=n;++j) for(k=1;k<=n;++k)
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+matrix[k][j]);
            }
            else{
                for(j=1;j<=n;++j)
                    dp[i][j]=dp[i-1][tmp]+matrix[tmp][j];
            }
        }
        ans=-1;
        if(tmp==-1)
            for(i=1;i<=n;++i) ans=max(ans,dp[m-1][i]);
        else
            ans=dp[m-1][tmp];
        printf("%d\n",ans);
    }
    return 0;
}