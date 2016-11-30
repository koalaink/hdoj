#include<iostream>
#include<queue>
using namespace std;

const int MAX=25;
char map[MAX][MAX];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,sx,sy,ex,ey;

struct point{
    int x,y,step;
    friend bool operator<(const point &a,const point &b){
        return a.step>b.step;
    }
};

bool gow(point p,int d){
    if(map[p.x][p.y]=='|'){
        if(d==0 || d==1){
            if(p.step%2==0)
                return false;
            else
                return true;
        }
        else{
            if(p.step%2==0)
                return true;
            else
                return false;
        }
    }
    else{
        if(d==0 || d==1){
            if(p.step%2==0)
                return true;
            else
                return false;
        }
        else{
            if(p.step%2==0)
                return false;
            else
                return true;
        }
    }
}

void bfs(){
    point now,next;
    now.x=sx;now.y=sy;now.step=0;
    map[sx][sy]='*';
    priority_queue<point> q;
    q.push(now);
    while(!q.empty()){
        now=q.top();q.pop();
        if(now.x==ex && now.y==ey){
            printf("%d\n",now.step);
            return ;
        }
        now.step++;
        for(int i=0;i<4;i++){
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            next.step=now.step;
            if(next.x<0 || next.x>=n || next.y<0 || next.y>=m || map[next.x][next.y]=='*') continue;
            if(map[next.x][next.y]!='-' && map[next.x][next.y]!='|'){
                map[next.x][next.y]='*';
                q.push(next);
            }
            else{
                if(gow(next,i)){
                    next.x+=dir[i][0];
                    next.y+=dir[i][1];
                    if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&map[next.x][next.y]!='*'){
                        map[next.x][next.y]='*';
                        q.push(next);
                    }
                }
                else q.push(now);
            }
        }
    }
    return ;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=0;j<m;j++){
                map[i][j]=temp[j];
                if(temp[j]=='S') sx=i,sy=j;
                if(temp[j]=='T') ex=i,ey=j;
            }
        }
        bfs();
    }
}