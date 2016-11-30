#include<iostream>
#include<string>
#include<queue>
using namespace std;

const int MAX=110;
char map[MAX][MAX];
int visit[MAX][MAX];
int n,m,flag;
int k,sx,sy,ex,ey;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct point{
    int x,y;
    int turn;
    int dir;
}st;

bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m&&map[x][y]!='*')
        return true;
    return false;
}

void bfs(){
    st.x=sx;st.y=sy;st.turn=-1;st.dir=-1;
    visit[sx][sy]=0;
    queue<point> q;
    q.push(st);
    while(!q.empty()){
        point now=q.front();q.pop();
        if(now.x==ex && now.y==ey && now.turn<=k ){
            flag=1;
            return ;
        }
        for(int i=0;i<4;i++){
            point next=now;
            next.x+=dir[i][0];next.y+=dir[i][1];
            if(check(next.x,next.y)){
                if(next.dir==-1){
                    next.dir=i;
                    next.turn=0;
                    if(visit[next.x][next.y]>=next.turn){
                        visit[next.x][next.y]=next.turn;
                        q.push(next);
                    }
                }
                else{
                    if(i==next.dir){
                        if(visit[next.x][next.y]>=next.turn){
                            visit[next.x][next.y]=next.turn;
                            q.push(next);
                        }
                    }
                    else{
                        next.turn++;next.dir=i;
                        if(next.turn<=k&&visit[next.x][next.y]>=next.turn){
                            visit[next.x][next.y]=next.turn;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=1;j<=m;j++){
                map[i][j]=temp[j-1];
                visit[i][j]=100000;
            }
        }
        scanf("%d%d%d%d%d",&k,&sy,&sx,&ey,&ex);
        if(sx==ex && sy==ey){
            printf("yes\n");
            continue;
        }
        flag=0;
        bfs();
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
