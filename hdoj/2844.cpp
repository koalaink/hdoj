#include<iostream>
#include<stdio.h>
using namespace std;

int n,m;
bool dp[100001];
int a[110],c[110];

void zeroonepack(int val){
    for(int i=m;i>=val;i--)
        dp[i]=dp[i]||dp[i-val];
}

void completepack(int val){
    for(int i=val;i<=m;i++)
        dp[i]=dp[i]||dp[i-val];
}

void multipack(int val,int count){
    if(val*count>=m){
        completepack(val);
        return ;
    }
    int k=1;
    while(k<count){
        zeroonepack(k*val);
        count-=k;
        k*=2;
    }
    zeroonepack(count*val);
}

int main(){
    int i,j,ans;
    while(scanf("%d%d",&n,&m),n||m){
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++) scanf("%d",&c[i]);
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        ans=0;
        for(i=0;i<n;i++)
            multipack(a[i],c[i]);
        for(i=1;i<=m;i++)
            if(dp[i]) ans++;
        printf("%d\n",ans);
    }
}