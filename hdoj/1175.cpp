#include<iostream>
using namespace std;

int n,m;                                    // 行列
int map[1010][1010];                        // 棋盘
int load[1010][1010];                        // 标记
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};    // 右 左 上 下
int sx,sy,ex,ey;                            // 起始点坐标
bool flag;

bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m&&(map[x][y]==0||x==ex&&y==ey))
        return true;
    return false;
}

void DFS(int x,int y,int count,int direction){
    if(flag || count>3 )
        return ;
    if( x==ex && y==ey ){
        flag=1;
        return ;
    }
    for(int i=0;i<4;i++){
        int nx,ny;
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(check(nx,ny) && count<load[nx][ny] ){
            if( direction==i && count<=3 && count<load[nx][ny] ){
                load[nx][ny]=count;
                DFS(nx,ny,count,direction);
            }
            if( (direction!=i || direction==-1) && count<load[nx][ny] ){
                load[nx][ny]=count+1;
                DFS(nx,ny,count+1,i);
            }
        }
    }
}

int main(){
    int c,l,t;
    while(scanf("%d%d",&n,&m)!=EOF,n+m){
        for(c=1;c<=n;++c)
            for(l=1;l<=m;++l)
                scanf("%d", &map[c][l]);
        scanf("%d",&t);
        while(t--){
            for(c=1;c<=n;++c)
                for(l=1;l<=m;++l)
                    load[c][l]=100000;
            scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
            if(map[sx][sy]==0 || map[ex][ey]==0 || map[sx][sy]!=map[ex][ey] )
                printf("NO\n");
            else{
                flag=0;
                DFS(sx,sy,0,-1);
                if(flag) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
