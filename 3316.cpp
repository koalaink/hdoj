#include<iostream>
#include<queue>
using namespace std;

const int MAX=101;
char map[MAX][MAX];
char vis[MAX][MAX];
int number[MAX][MAX];
int sx,sy,n;
int dir[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

struct point{
    int x,y;
};

int findmine(int x,int y){
    if(map[x][y]=='X') return 0;
    int num=0,i,a,b;
    for(i=0;i<8;i++){
        a=x+dir[i][0];b=y+dir[i][1];
        if(a>=0&&a<n&&b>=0&&b<n&&map[a][b]=='X')
            num++;
    }
    return num;
}

void bfs(){
    if(map[sx][sy]=='X'){
        printf("it is a beiju!\n\n");
        return ;
    }
    point now,next;
    now.x=sx;now.y=sy;
    vis[sx][sy]=(char)(number[sx][sy]+'0');
    queue<point> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        if(number[now.x][now.y]==0){
            for(int i=0;i<8;i++){
                next.x=now.x+dir[i][0];next.y=now.y+dir[i][1];
                if(next.x>=0&&next.x<n&&next.y>=0&&next.y<n&&vis[next.x][next.y]=='.'){
                    vis[next.x][next.y]=(char)(number[next.x][next.y]+'0');
                    q.push(next);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%s\n",vis+i);
    printf("\n");
    return ;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=0;j<n;j++){
                map[i][j]=temp[j];
                vis[i][j]='.';
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                number[i][j]=findmine(i,j);
        scanf("%d%d",&sx,&sy);
        bfs();
    }
    return 0;
}
