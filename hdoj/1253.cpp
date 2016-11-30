#include<iostream>
#include<queue>
using namespace std;

const int MAX=51;
bool map[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int a,b,c,t,flag;
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

struct point{
    int x,y,z;
    int time;
};

bool check(int x,int y,int z){
    if(x>=1&&x<=a&&y>=1&&y<=b&&z>=1&&z<=c&&!map[x][y][z])
        return true;
    return false;
}

void bfs(){
    point now,next;
    now.x=now.y=now.z=1;now.time=0;
    visit[1][1][1]=true;
    queue<point> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.x==a&&now.y==b&&now.z==c&&now.time<=t){
            flag=now.time;return ;
        }
        if(now.time>t) return ;
        for(int i=0;i<6;i++){
            next=now;
            next.x+=dir[i][0];next.y+=dir[i][1];next.z+=dir[i][2];
            if(check(next.x,next.y,next.z)&&!visit[next.x][next.y][next.z]){
                visit[next.x][next.y][next.z]=true;
                next.time++;
                q.push(next);
            }
        }
    }
    return ;
}

int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        scanf("%d%d%d%d",&a,&b,&c,&t);
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int k=1;k<=c;k++){
                    scanf("%d",map[i][j]+k);
                    visit[i][j][k]=false;
                }
            }
        }
        if(map[a][b][c]){
            printf("-1\n");
            continue;
        }
        flag=-1;
        bfs();
        printf("%d\n",flag);
    }
    return 0;
}
