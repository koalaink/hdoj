/*
sample input:
111111 222222
896521 183995
 */
#include <iostream>
#include <memory.h>
#include <string.h>
#include <stdio.h>
#define MAX 1005
using namespace std;

int len;
int dp[MAX][10][10];
char s1[MAX],s2[MAX];

int main(){
    int i,j,k,x,y;
    // freopen("0input.txt","r",stdin);
    while(scanf("%s %s",s1,s2)!=EOF){
        len=strlen(s1);
        memset(dp,0x7f,sizeof(dp));
        dp[0][0][0]=0;
        for(i=0;i<len;++i){
            for(j=0;j<10;++j){
                int up=(s2[i]-s1[i]-j+20)%10;
                int dw=(10-up)%10;
                for(k=0;k<10;++k){
                    for(x=0;x<=up;++x) for(y=0;y<=x;++y){
                        int t=(k+x)%10;
                        dp[i+1][t][y]=min(dp[i+1][t][y],dp[i][j][k]+up);
                    }
                    for(x=0;x<=dw;++x) for(y=0;y<=x;++y){
                        int t=(k-x+10)%10;
                        dp[i+1][t][(10-y)%10]=min(dp[i+1][t][(10-y)%10],dp[i][j][k]+dw);
                    }
                }
            }
        }
        printf("%d\n",dp[len][0][0]);
    }
    return 0;
}