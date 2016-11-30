#include<iostream>
#include<stdio.h>
using namespace std;

double dp[10001];
int a[1001];
double p[1001];

int main(){
    int n,m,i,j;
    while(scanf("%d%d",&n,&m),n||m){
        for(i=0;i<m;i++){
            scanf("%d%lf",&a[i],&p[i]);
            p[i]=1-p[i];
        }
        for(i=0;i<=n;i++) dp[i]=1;
        for(i=0;i<m;i++){
            for(j=n;j>=a[i];j--){
                dp[j]=dp[j]<dp[j-a[i]]*p[i]?dp[j]:dp[j-a[i]]*p[i];
            }
        }
        printf("%.1lf%%\n",(1-dp[n])*100);
    }
}