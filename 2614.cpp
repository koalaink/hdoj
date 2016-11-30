#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX=15;
int pro[MAX][MAX];
bool solved_l[MAX];
int n,ans;
bool flag;

void dfs(int id,int time,int solved){
    if(flag) return ;
    for(int i=0;i<n;i++){
        if(!solved_l[i]){
            if(pro[id][i]>=time){
                ans=(ans>(solved+1))?(ans):(solved+1);
                if(ans==n){
                    flag=true;
                    return ;
                }
                solved_l[i]=true;
                dfs(i,pro[id][i],solved+1);
                solved_l[i]=false;
            }
        }
    }
    return ;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&pro[i][j]);
        flag=false;
        ans=0;
        memset(solved_l,false,sizeof(solved_l));
        solved_l[0]=true;
        dfs(0,0,1);
        printf("%d\n",ans);
    }
    return 0;
}