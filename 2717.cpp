/*
sample input:
5 17
*/
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <queue>
using namespace std;

bool flag[200005];

struct node{
    int x;
    int step;
    bool check(){
        return x>-100001&&x<100001;
    }
};

int n,k;
int ans;

void bfs(){
    queue<node> q;
    node cur,nex;
    cur.x=n;
    cur.step=0;
    memset(flag,false,sizeof(flag));
    flag[n+100000]=true;
    q.push(cur);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(cur.x==k){
            ans=cur.step;
            return ;
        }
        nex.step=cur.step+1;
        nex.x=cur.x+1;
        if(nex.check()&&!flag[nex.x+100000]){
            flag[nex.x+100000]=true;
            q.push(nex);
        }
        nex.x=cur.x-1;
        if(nex.check()&&!flag[nex.x+100000]){
            flag[nex.x+100000]=true;
            q.push(nex);
        }
        nex.x=cur.x*2;
        if(nex.check()&&!flag[nex.x+100000]){
            flag[nex.x+100000]=true;
            q.push(nex);
        }
    }
    return ;
}

int main(){
    // freopen("0input.txt","r",stdin);
    while(scanf("%d%d",&n,&k)!=EOF){
        ans=0;
        bfs();
        printf("%d\n",ans);
    }
    return 0;
}