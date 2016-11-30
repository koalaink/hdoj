#include<iostream>
#include<queue>
using namespace std;

const int MAX=110;
char map[MAX][MAX];
int vis[MAX][MAX];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,ans;

struct point{
    int x,y,time;
};

struct node{
    int x,y;
};

bool check(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]!='X')
        return true;
    return false;
}

int bfs(){
    point now,next;
    now.x=now.y=now.time=0;
    vis[0][0]=0;
    queue<point> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        for(int i=0;i<4;i++){
            next.x=now.x+dir[i][0];next.y=now.y+dir[i][1];
            if(check(next.x,next.y)){
                next.time=now.time+1;
                if(map[next.x][next.y]!='.') next.time+=map[next.x][next.y]-'0';
                if(next.time>=vis[next.x][next.y]) continue;
                vis[next.x][next.y]=next.time;
                q.push(next);
            }
        }
    }
    return vis[n-1][m-1];
}

int findpre(int x,int y){
    int st=vis[x][y]-1;
    if(map[x][y]!='.') st-=map[x][y]-'0';
    for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(vis[nx][ny]==st) return i;
    }
}

bool find(int x,int y){
    if(x==0&&y==0) return true;
    int i=findpre(x,y);
    int nx=x+dir[i][0],ny=y+dir[i][1];
    if(find(nx,ny)){
        if(map[x][y]!='.'){
            int t=map[x][y]-'0';
            printf("%ds:(%d,%d)->(%d,%d)\n",vis[x][y]-t,nx,ny,x,y);
            for(int j=1;j<=t;j++) printf("%ds:FIGHT AT (%d,%d)\n",vis[x][y]-t+j,x,y);
        }else printf("%ds:(%d,%d)->(%d,%d)\n",vis[x][y],nx,ny,x,y);
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=0;j<m;j++){
                map[i][j]=temp[j];
                vis[i][j]=100000;
            }
        }
        int ans=bfs();
        if(ans==100000) printf("God please help our poor hero.\nFINISH\n");
        else{
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
            find(n-1,m-1);
            printf("FINISH\n");
        }
    }
}