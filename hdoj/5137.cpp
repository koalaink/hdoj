/*
sample input:
4 5
1 2 3
1 3 7
1 4 50
2 3 4
3 4 2
3 2
1 2 30
2 3 10
2 1
1 2 30
0 0
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <queue>
#define MAX 1005
#define INF 0x7fffffff
using namespace std;

struct node{
    int v,w;
    int next;
}edge[MAX<<1];

int n,m;
int head[MAX];
int dist[MAX];
int vist[MAX];
int path[MAX];
int now;

void init(){
    memset(head,-1,sizeof(head));
    now=0;
}

void add(int u,int v,int w){
    edge[now].v=v;
    edge[now].w=w;
    edge[now].next=head[u];
    head[u]=now++;
}

void spfa(int s,int del){
    int i,j;
    for(i=1;i<=n;++i){
        del==-1?path[i]=-1:0;
        dist[i]=INF;
        vist[i]=false;
    }
    dist[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int cur=q.front();q.pop();
        vist[cur]=false;
        for(i=head[cur];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(v==del) continue;
            if(dist[v]>dist[cur]+edge[i].w){
                dist[v]=dist[cur]+edge[i].w;
                del==-1?path[v]=cur:0;
                if(!vist[v]){
                    vist[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return ;
}

int main(){
    int u,v,w;
    // freopen("0input.txt","r",stdin);
    while(scanf("%d%d",&n,&m),n+m){
        init();
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        spfa(1,-1);
        int ans=dist[n];
        for(int i=path[n];i!=1;i=path[i]){
            spfa(1,i);
            if(dist[n]>ans) ans=dist[n];
        }
        if(ans==INF) printf("Inf\n");
        else printf("%d\n",ans);
    }
    return 0;
}