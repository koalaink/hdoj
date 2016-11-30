#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

const int MAX=205;
char a[MAX],b[MAX],c[2*MAX];
bool vis[MAX][MAX];
int l1,l2,len;
bool flag;

void dfs(int i,int j,int k){
    if(flag) return ;
    if(k==len){
        flag=true;
        return ;
    }
    if(vis[i][j]) return ;
    vis[i][j]=true;
    if(a[i]==c[k])
        dfs(i+1,j,k+1);
    if(flag) return ;
    if(b[j]==c[k])
        dfs(i,j+1,k+1);
    return ;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%s%s%s",a,b,c);
        l1=strlen(a);
        l2=strlen(b);
        len=strlen(c);
        flag=false;
        memset(vis,false,sizeof(vis));
        dfs(0,0,0);
        printf("Data set %d: ",i);
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}