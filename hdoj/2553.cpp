#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX=15;
int map[MAX];
bool col[MAX];
int ans,a_ans[MAX];
int n;

void dfs(int index){
    bool flag;
    if(index==n){
        ans++;
        return ;
    }
    for(int i=0;i<n;i++){
        if(!col[i]){
            map[index]=i;
            flag=true;
            for(int j=0;j<index;j++){
                if( (map[index]-map[j])==(index-j) || (map[index]-map[j])==(j-index) ){
                    flag=false;
                    break;
                }
            }
            if(flag){
                col[i]=true;
                dfs(index+1);
                col[i]=false;
            }
        }
    }
    return ;
}

int main(){
    for(int i=1;i<11;i++){
        n=i;
        ans=0;
        memset(map,0,sizeof(map));
        memset(col,false,sizeof(col));
        dfs(0);
        a_ans[i]=ans;
    }
    while(scanf("%d",&n),n)
        printf("%d\n",a_ans[n]);
}