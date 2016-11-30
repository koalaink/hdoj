#include<iostream>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

const int MAX=101;
char map[MAX][MAX];
bool visit[MAX][MAX];
int n,m,t;
int sx,sy,ex,ey;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

bool dfs(int x,int y,int step){
    if(map[x][y]=='D' && t==step) return true;
    int a,b;
    if(step>=t) return false;
    if(t-step<(abs(x-ex)+abs(y-ey))) return false;
    if((t-step-(abs(x-ex)+abs(y-ey)))%2!=0)    return false;
    for(int i=0;i<4;i++){
        a=x+dir[i][0];b=y+dir[i][1];
        if(a<=n&&a>=1&&b>=1&&b<=m&&map[a][b]!='X'&&!visit[a][b]){
            visit[a][b]=true;
            if(dfs(a,b,step+1)) return true;
            else visit[a][b]=false;
        }
    }
    return false;
}

int main(){
    while(scanf("%d%d%d",&n,&m,&t)!=EOF,n+m+t){
        for(int i=1;i<=n;i++){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=1;j<=m;j++){
                map[i][j]=temp[j-1];
                if(map[i][j]=='S'){
                    sx=i;sy=j;
                }else if(map[i][j]=='D'){
                    ex=i;ey=j;
                }
                visit[i][j]=false;
            }
        }
        visit[sx][sy]=true;
        if(dfs(sx,sy,0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
