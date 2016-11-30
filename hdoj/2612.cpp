#include<iostream>
#include<queue>
using namespace std;

const int MAX=201;
char map[MAX][MAX];
int ans[MAX][MAX];
bool vis[MAX][MAX],flag;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,sx,sy,ex,ey;

struct point{
    int x,y;
    int step;
};

void bfs(int x,int y){
    memset(vis,0,sizeof(vis));
    point now,next;
    now.x=x;now.y=y;now.step=0;
    vis[x][y]=true;
    queue<point> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        for(int i=0;i<4;i++){
            next.x=now.x+dir[i][0];next.y=now.y+dir[i][1];next.step=now.step+1;
            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&map[next.x][next.y]!='#'&&!vis[next.x][next.y]){
                if(map[next.x][next.y]=='@'){
                    if(!flag){
                        ans[next.x][next.y]=next.step;
                    }else if(ans[next.x][next.y]){
                        ans[next.x][next.y]+=next.step;
                    }
                    vis[next.x][next.y]=true;
                }
                vis[next.x][next.y]=true;
                q.push(next);
            }
        }
    }
    flag=true;
    return ;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;++i){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=0;j<m;++j){
                map[i][j]=temp[j];
                if(temp[j]=='Y'){
                    sx=i;sy=j;
                }
                if(temp[j]=='M'){
                    ex=i;ey=j;
                }
            }
        }
        memset(ans,0,sizeof(ans));
        flag=false;
        bfs(sx,sy);bfs(ex,ey);
        int min=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(ans[i][j]){
                    if(!min) min=ans[i][j];
                    else if(min>ans[i][j]) min=ans[i][j];
                }
        printf("%d\n",11*min);
    }
}