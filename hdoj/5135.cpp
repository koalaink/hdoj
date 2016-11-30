/*
sample input:
3
1 1 20
7
3 4 5 3 4 5 90
3
2 1 1
6
1 1 2 3 3 3
0
 */
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int n;
double ans;
int arr[15];
bool vis[15];

double isTri(int a,int b,int c){
    if(a+b<=c) return 0;
    double p=((double)a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void dfs(int num,double sum){
    ans=ans>sum?ans:sum;
    if((n-num*3)<3) return ;
    int i,j,k;
    for(i=0;i<n-2;++i){
        if(vis[i]) continue;
        for(j=i+1;j<n-1;++j){
            if(vis[j]) continue;
            for(k=j+1;k<n;++k){
                if(vis[k]) continue;
                double area=isTri(arr[i],arr[j],arr[k]);
                if(area!=0){
                    vis[i]=vis[j]=vis[k]=true;
                    dfs(num+1,sum+area);
                    vis[i]=vis[j]=vis[k]=false;
                }
            }
        }
    }
    return ;
}

int main(){
    // freopen("0input.txt","r",stdin);
    while(scanf("%d",&n),n){
        for(int i=0;i<n;++i) scanf("%d",&arr[i]);
        sort(arr,arr+n);
        memset(vis,false,sizeof(vis));
        ans=0;
        dfs(0,0);
        printf("%.2lf\n",ans);
    }
    return 0;
}