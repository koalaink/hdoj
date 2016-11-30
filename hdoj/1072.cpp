#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

const int MAX=10;
int map[MAX][MAX];
int vis[MAX][MAX];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int n,m,sx,sy,ex,ey,ans;

struct node{
    int x,y,rt,step;
};

bool check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && map[x][y])
        return true;
    return false;
}

void bfs(){
    queue<node> q;
    node now,next;
    now.x=sx;now.y=sy;now.step=0;now.rt=6;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.x==ex && now.y==ey){
            ans=now.step;
            return ;
        }
        if(now.rt<=1) continue;
        for(int i=0;i<4;i++){
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            next.step=now.step+1;
            if(check(next.x,next.y)){
                if(map[next.x][next.y]==4){
                    if(vis[next.x][next.y]<6){
                        vis[next.x][next.y]=6;
                        next.rt=6;
                        q.push(next);
                    }
                }else{
                    if(vis[next.x][next.y]<now.rt-1){
                        vis[next.x][next.y]=now.rt-1;
                        next.rt=now.rt-1;
                        q.push(next);
                    }
                }
            }
        }
    }
    return ;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==2) sx=i,sy=j;
                else if(map[i][j]==3) ex=i,ey=j;
            }
        memset(vis,0,sizeof(vis));
        vis[sx][sy]=6;
        ans=-1;
        bfs();
        printf("%d\n",ans);
    }
}