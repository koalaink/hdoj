/*
1
4 4 22 0 3
1 1 1 1
5 7 9 12
0 1 10
1 3 10
0 2 10
2 3 10
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
#define MAX 105
#define INF 0x7fff
using namespace std;

int ci[MAX];
int si[MAX];
int dist[MAX][MAX];
int dp[MAX][MAX][MAX*3];
int n,m,t,s,e;

void floyd(){
    int i,j,k;
    for(i=0;i<n;++i) dist[i][i]=0;
    for(k=0;k<n;++k) for(i=0;i<n;++i) for(j=0;j<n;++j){
        if(dist[i][j]>dist[i][k]+dist[k][j]) dist[i][j]=dist[i][k]+dist[k][j];
    }
    return ;
}

int dfs(int u,int lsi,int lt){
    if(dist[u][e]>lt) return -INF;
    if(dp[u][lsi][lt]!=-1) return dp[u][lsi][lt];
    int ans=0;
    for(int i=0;i<n;++i){
        if(si[i]<=lsi) continue;
        ans=max(ans,dfs(i,si[i],lt-ci[i]-dist[u][i])+si[i]);
    }
    return dp[u][lsi][lt]=ans;
}

int main(){
    int T,cas=1;
    int i,j,u,v,l;
    freopen("0input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&n,&m,&t,&s,&e);
        for(i=0;i<n;++i) scanf("%d",&ci[i]);
        for(i=0;i<n;++i) scanf("%d",&si[i]);
        for(i=0;i<n;++i) for(j=0;j<n;++j) dist[i][j]=INF;
        while(m--){
            scanf("%d%d%d",&u,&v,&l);
            dist[u][v]=dist[u][v]>l?(dist[v][u]=l):dist[u][v];
        }
        floyd();
        memset(dp,-1,sizeof(dp));
        printf("Case #%d:\n%d\n",cas++,dfs(s,0,t));
    }
    return 0;
}