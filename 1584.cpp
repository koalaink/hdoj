#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int card[11];
bool used[11];
int ans;

void dfs(int step,int round){
    if(step>ans) return ;
    if(round==9){
        ans=step;
        return ;
    }
    for(int i=1;i<=10;i++){
        if(!used[i]){
            for(int j=i+1;j<=10;j++){
                if(!used[j]){
                    used[i]=true;
                    dfs(step+abs(card[i]-card[j]),round+1);
                    break;
                }
            }
            used[i]=false;
        }
    }
    return ;
}

int main(){
    int t,num;
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=10;++i){
            scanf("%d",&num);
            card[num]=i;
        }
        memset(used,false,sizeof(used));
        ans=0xfffffff;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}