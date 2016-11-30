#include<iostream>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

const int MAX=11;
char map[3][MAX][MAX];
bool visit[2][MAX*2][MAX],flag;
int n,m,t;
int sf,sx,sy,ef,ex,ey;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

struct point{
    int f,x,y;
    int time;
};

bool check(int f,int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m&&map[f][x][y]!='*')
        return true;
    return false;
}

void bfs(){
    point now,next;
    now.f=sf;now.x=sx;now.y=sy;now.time=0;
    visit[sf][sx][sy]=true;
    queue<point> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.f==ef&&now.x==ex&&now.y==ey&&now.time<=t){
            flag=true;return ;
        }
        if(now.time>t) return ;
        for(int i=0;i<4;i++){
            next=now;
            next.x+=dir[i][0];next.y+=dir[i][1];
            if(check(next.f,next.x,next.y)&&!visit[next.f][next.x][next.y]){
                if(map[next.f][next.x][next.y]=='#'){
                    (next.f==1)?(next.f=2):(next.f=1);
                    if(map[next.f][next.x][next.y]=='*'||map[next.f][next.x][next.y]=='#') continue;
                    visit[1][next.x][next.y]=visit[2][next.x][next.y]=true;
                }
                next.time++;
                visit[next.f][next.x][next.y]=true;
                q.push(next);
            }
        }
    }
    return ;
}

int main(){
    int c;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d%d",&n,&m,&t);
        for(int i=1;i<3;i++){
            for(int j=1;j<=n;j++){
                char temp[MAX];
                scanf("%s",temp);
                for(int k=1;k<=m;k++){
                    map[i][j][k]=temp[k-1];
                    if(map[i][j][k]=='P'){
                        ef=i;ex=j;ey=k;
                    }else if(map[i][j][k]=='S'){
                        sf=i;sx=j;sy=k;
                    }
                    visit[i][j][k]=false;
                }
            }
        }
        flag=false;
        bfs();
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
