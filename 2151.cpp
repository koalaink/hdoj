/*
sample input:
3 2 4 2
3 2 3 2
*/
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <cmath>
using namespace std;

int n,p,m,t;
int ans;

int dp[105][105];

int main(){
    // freopen("0input.txt","r",stdin);
    while(scanf("%d%d%d%d",&n,&p,&m,&t)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[0][p-1]=1;
        for(int i=1;i<=m;++i){
            for(int j=0;j<n;++j){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            }
        }
        printf("%d\n",dp[m][t-1]);
    }
    return 0;  
}