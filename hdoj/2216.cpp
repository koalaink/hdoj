#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

const int MAX=25;
char map[MAX][MAX];
bool vis[MAX][MAX][MAX][MAX];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
struct point{
    int sx,sy,ex,ey,step;
};

void bfs(point s){
    point now,next;
    queue<point> q;
    q.push(s);
    vis[s.sx][s.sy][s.ex][s.ey]=true;
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.sx==now.ex&&abs(now.sy-now.ey)<=1 || now.sy==now.ey&&abs(now.sx-now.ex)<=1){
            printf("%d\n",now.step);
            return ;
        }
        for(int i=0;i<4;i++){
            next.sx=now.sx+dir[i][0];
            next.sy=now.sy+dir[i][1];
            next.step=now.step+1;
            if(next.sx>=0 && next.sx<n && next.sy>=0 && next.sy<m && map[next.sx][next.sy]!='X'){
                next.ex=now.ex-dir[i][0];
                next.ey=now.ey-dir[i][1];
                if(next.ex>=0 && next.ex<n && next.ey>=0 && next.ey<m && map[next.ex][next.ey]!='X'){
                    if(!vis[next.sx][next.sy][next.ex][next.ey]){
                        vis[next.sx][next.sy][next.ex][next.ey]=true;
                        q.push(next);
                    }
                }else{
                    next.ex=now.ex;next.ey=now.ey;
                    if(!vis[next.sx][next.sy][next.ex][next.ey]){
                        vis[next.sx][next.sy][next.ex][next.ey]=true;
                        q.push(next);
                    }
                }
            }
        }
    }
    printf("Bad Luck!\n");
    return ;
}

int main(){
    point s;
    s.step=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=0;j<m;j++){
                map[i][j]=temp[j];
                if(temp[j]=='Z') s.sx=i,s.sy=j;
                if(temp[j]=='S') s.ex=i,s.ey=j;
            }
        }
        memset(vis,0,sizeof(vis));
        bfs(s);
    }
    return 0;
}