#include<iostream>
#include<stdio.h>
using namespace std;

char map[5][5];
bool vis[5][5];
int n,ans;

bool check(int i,int j){
    if(map[i][j]!='.') return false;
    int a;
    for(a=i-1;a>=1;--a){
        if(map[a][j]=='X') break;
        if(map[a][j]=='B') return false;
    }
    for(a=j-1;a>=1;--a){
        if(map[i][a]=='X') break;
        if(map[i][a]=='B') return false;
    }
    return true;
}

void dfs(int num,int sum){
    if(num==n*n){
        ans=ans>sum?ans:sum;
        return ;
    }
    int i,j;
    i=num/n+1;
    j=num%n+1;
    if(check(i,j)){
        map[i][j]='B';
        dfs(num+1,sum+1);
        map[i][j]='.';
    }
    dfs(num+1,sum);
    return ;
}

int main(){
    while(scanf("%d",&n),n){
        ans=0;
        memset(map,'X',sizeof(map));
        for(int i=1;i<=n;i++){
            char temp[5];
            scanf("%s",temp);
            for(int j=1;j<=n;j++)
                map[i][j]=temp[j-1];
        }
        dfs(0,0);
        printf("%d\n",ans);
    }
}