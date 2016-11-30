#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX=35;
int dis[MAX][MAX];
int mark[MAX];
int NCITY,k,ans;

void dfs(int arr,int now,int time){
    if(arr==0){
        ans=ans>time?time:ans;
        return ;
    }
    for(int i=1;i<NCITY;i++){
        if(mark[i]){
            mark[i]=false;
            dfs(arr-1,i,time+dis[now][i]);
            mark[i]=true;
        }
    }
    return ;
}

int main(){
    while(scanf("%d",&NCITY),NCITY){
        for(int i=0;i<NCITY;i++)
            for(int j=0;j<NCITY;j++)
                scanf("%d",&dis[i][j]);
        memset(mark,false,sizeof(mark));
        scanf("%d",&k);
        int temp=0,a;
        for(int i=0;i<k;i++){
            scanf("%d",&a);
            if(!mark[a]){
                mark[a]=true;
                temp++;
            }
        }
        ans=0xffffff;
        dfs(temp,0,0);
        printf("%d\n",ans);
    }
}