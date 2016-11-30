#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX=1005;
int f[100005];
int things[MAX][2];
int sum;

void zeroonepack(int val){
    for(int i=sum/2;i>=val;i--)
        f[i]=(f[i]>(f[i-val]+val))?f[i]:(f[i-val]+val);
}

void completepack(int val){
    for(int i=val;i<=sum/2;i++)
        f[i]=(f[i]>(f[i-val]+val))?f[i]:(f[i-val]+val);
}

void multipack(int val,int num){
    if(val*num>=sum/2){
        completepack(val);
        return ;
    }
    int k=1;
    while(k<num){
        zeroonepack(val*k);
        num-=k;
        k*=2;
    }
    zeroonepack(num*val);
}

int main(){
    int n;
    while(scanf("%d",&n)){
        if(n<0) break;
        sum=0;
        for(int i=0;i<n;i++) scanf("%d%d",&things[i][0],&things[i][1]),sum+=things[i][0]*things[i][1];
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            multipack(things[i][0],things[i][1]);
        printf("%d %d\n",sum-f[sum/2],f[sum/2]);
    }
}