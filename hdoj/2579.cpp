#include<iostream>
#include<queue>
using namespace std;

const int MAX=101;
char map[MAX][MAX];
int vis[MAX][MAX][10];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int r,c,k,sx,sy,ex,ey;

struct point{
    int x,y;
    int time;
};

void bfs(){
    point now,next;
    now.x=sx;now.y=sy;now.time=0;
    vis[sx][sy][0]=0;
    queue<point> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.x==ex&&now.y==ey){
            printf("%d\n",now.time);
            return ;
        }
        for(int i=0;i<4;i++){
            next.x=now.x+dir[i][0];next.y=now.y+dir[i][1];next.time=now.time+1;
            if(next.x>=0&&next.x<r&&next.y>=0&&next.y<c){
                if(map[next.x][next.y]=='#'&&next.time%k!=0) continue;
                if(next.time>=vis[next.x][next.y][next.time%k]) continue;
                vis[next.x][next.y][next.time%k]=next.time;
                q.push(next);
            }
        }
    }
    printf("Please give me another chance!\n");
    return ;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&r,&c,&k);
        for(int i=0;i<r;++i){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=0;j<c;++j){
                map[i][j]=temp[j];
                for(int a=0;a<k;a++)
                    vis[i][j][a]=100;
                if(temp[j]=='Y'){
                    sx=i;sy=j;
                }else if(temp[j]=='G'){
                    ex=i;ey=j;
                }
            }
        }
        bfs();
    }
}