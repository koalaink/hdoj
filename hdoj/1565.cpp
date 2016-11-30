/*
sample input:
3
75 15 21 
75 15 28 
34 70 5
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

const int MAX=1<<20;
int dp[2][1<<20];


int main(){
    // freopen("0input.txt","r",stdin);
    int n,i,j,k;
    int cur,pre;
    int tmp;
    int ans;
    while(scanf("%d",&n)!=EOF){
        memset(dp,-1,sizeof(dp));
        cur=0;pre=1;
        dp[pre][0]=0;
        for(i=0;i<n;++i) for(j=0;j<n;++j){
            scanf("%d",&tmp);
            memset(dp[cur],-1,sizeof(dp[cur]));
            for(k=0;k<MAX;++k) if(~dp[pre][k]){
                int t=k&(~(1<<j));
                dp[cur][t]=max(dp[cur][t],dp[pre][k]);
                if( !(k&(1<<j))&&(j==0||(j>0&&!(k&(1<<(j-1))))) )
                    dp[cur][k^(1<<j)]=max(dp[pre][k]+tmp,dp[cur][k^(1<<j)]);
            }
            swap(cur,pre);
        }
        ans=0;
        for(i=0;i<MAX;++i) if(~dp[pre][i]){
            ans=max(ans,dp[pre][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}