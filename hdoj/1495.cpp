#include<iostream>
#include<queue>
using namespace std;

const int MAX=110;
bool vis[MAX][MAX][MAX];
int s,m,n;

struct level{
    int s,m,n,step;
};

void bfs(){
    level now,next;
    now.s=s;
    now.m=0;
    now.n=0;
    now.step=0;
    queue<level> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.s==now.m && now.n==0){    printf("%d\n",now.step);return ;}
        next=now;
        next.step++;
        if(now.m==0){
            next.m=m;
            next.s-=m;
            if(vis[next.s][next.m][next.n]) break;
            vis[next.s][next.m][next.n]=true;
            q.push(next);
            continue;
        }
        if(now.n==n){
            next.s+=n;
            next.n=0;
            if(vis[next.s][next.m][next.n]) break;
            vis[next.s][next.m][next.n]=true;
            q.push(next);
            continue;
        }
        if(now.m!=0){
            if(now.m>n-now.n){
                next.m=next.m-n+next.n;
                next.n=n;
                if(vis[next.s][next.m][next.n]) break;
                vis[next.s][next.m][next.n]=true;
                q.push(next);
                continue;
            }else{
                next.n+=next.m;
                next.m=0;
                if(vis[next.s][next.m][next.n]) break;
                vis[next.s][next.m][next.n]=true;
                q.push(next);
                continue;
            }
        }
    }
    printf("NO\n");
    return ;
}

int main(){
    while(scanf("%d%d%d",&s,&m,&n)!=EOF,s+m+n){
        if(m<n){
            int temp=m;m=n;n=temp;
        }
        memset(vis,0,sizeof(vis));
        bfs();
    }
}