#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX=15;
int s[MAX];
int ans[MAX];
int t,n,t_index;
bool flag;

void dfs(int index,int sum){
    if(sum>t) return ;
    if(sum==t){
        flag=true;
        for(int i=0;i<t_index-1;i++)
            printf("%d+",ans[i]);
        printf("%d\n",ans[t_index-1]);
        return ;
    }
    int pre=-1;
    for(int i=index+1;i<n;i++){
        if(s[i]!=pre){
            pre=s[i];
            ans[t_index++]=s[i];
            dfs(i,sum+s[i]);
            t_index--;
        }
    }
    return ;
}

int main(){
    int i;
    while(scanf("%d%d",&t,&n),t||n){
        for(i=0;i<n;i++) scanf("%d",s+i);
        flag=false;
        t_index=0;
        printf("Sums of %d:\n",t);
        dfs(-1,0);
        if(!flag) printf("NONE\n");
    }
}