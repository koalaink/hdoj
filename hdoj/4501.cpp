#include<iostream>
#include<stdio.h>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int main(){
    int dp[101][101][10];
    int n,v1,v2,k,i,x,y,z;
    int a,b,val;
    while(scanf("%d%d%d%d",&n,&v1,&v2,&k)!=EOF){
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++){
            scanf("%d%d%d",&a,&b,&val);
            for(x=v1;x>=0;x--){
                for(y=v2;y>=0;y--){
                    for(z=k;z>=0;z--){
                        int changemax=0;
                        if(x>=a)
                            changemax=max(changemax,dp[x-a][y][z]+val);
                        if(y>=b)
                            changemax=max(changemax,dp[x][y-b][z]+val);
                        if(z>0)
                            changemax=max(changemax,dp[x][y][z-1]+val);
                        dp[x][y][z]=max(changemax,dp[x][y][z]);
                    }
                }
            }
        }
        printf("%d\n",dp[v1][v2][k]);
    }
    return 0;
}