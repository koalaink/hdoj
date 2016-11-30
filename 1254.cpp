#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

const int MAX=10;
int map[MAX][MAX];
bool vis[MAX][MAX][4];
int m,n,sx,sy,ex,ey,px,py,ans;
int dir[4][2]={1,0,-1,0,0,1,0,-1};

struct node{
    int x;
    int y;
    int px;
    int py;
    int step;
    
};

bool check(int x,int y){
    if(x>=0 && x<m && y>=0 && y<n && map[x][y]!=1)
        return true;
    return false;
}

bool p_bfs(const node& v,int pex,int pey){
    queue<node> qu;
    node r,s;
    r=v;
    bool flag[MAX][MAX];
    memset(flag,false,sizeof(flag));
    if(r.px==pex&&r.py==pey) return true;
    qu.push(r);
    flag[r.px][r.py]=true;
    while(!qu.empty()){
        r=qu.front();qu.pop();
        for(int i=0;i<4;i++){
            s=r;
            s.px+=dir[i][0];
            s.py+=dir[i][1];
            if(check(s.px,s.py)&&!flag[s.px][s.py]&&map[s.px][s.py]!=1&&(s.px!=v.x||s.py!=v.y)){
                flag[s.px][s.py]=true;
                if(s.px==pex&&s.py==pey) return true;
                qu.push(s);
            }
        }
    }
    return false;
}

void b_bfs(){
    queue<node> q;
    node now,next,np;
    now.x=sx;now.y=sy;
    now.px=px;now.py=py;
    now.step=0;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.x==ex && now.y==ey){
            ans=now.step;
            return ;
        }
        for(int i=0;i<4;i++){
            next=now;
            next.step++;
            next.x+=dir[i][0];
            next.y+=dir[i][1];
            if(check(next.x,next.y)&&!vis[next.x][next.y][i]){
                np.x=now.x-dir[i][0];
                np.y=now.y-dir[i][1];
                if(!check(np.x,np.y)) continue;
                if(p_bfs(now,np.x,np.y)){
                    next.px=np.x;
                    next.py=np.y;
                    vis[next.x][next.y][i]=true;
                    q.push(next);
                }
            }
        }
    }
    return ;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==2) sx=i,sy=j;
                else if(map[i][j]==3) ex=i,ey=j;
                else if(map[i][j]==4) px=i,py=j;
            }
        }
        memset(vis,false,sizeof(vis));
        ans=0xffffff;
        b_bfs();
        ans==0xffffff?printf("-1\n"):printf("%d\n",ans);
    }
}