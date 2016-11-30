/*
sample input:
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <queue>
using namespace std;

struct node{
    int x;
    int y;
    int step;
    bool check(){
        if(x<0||x>7||y<0||y>7)
            return false;
        return true;
    }
};

int ans;
int ex,ey;
node cur,nex;
bool vis[10][10];
int dir[8][2]={-2,1,2,1,-2,-1,2,-1,-1,2,-1,-2,1,-2,1,2};

void bfs(){
    queue<node> q;
    memset(vis,false,sizeof(vis));
    cur.step=0;
    vis[cur.x][cur.y]=true;
    q.push(cur);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(cur.x==ex&&cur.y==ey){
            ans=cur.step;
            return ;
        }
        for(int i=0;i<8;++i){
            nex=cur;
            nex.step++;
            nex.x+=dir[i][0];
            nex.y+=dir[i][1];
            if(nex.check()&&!vis[nex.x][nex.y]){
                vis[nex.x][nex.y]=true;
                q.push(nex);
            }
        }
    }
    return ;
}

int main(){
    // freopen("0input.txt","r",stdin);
    char s1[5],s2[5];
    while(scanf("%s %s",s1,s2)!=EOF){
        cur.y=s1[0]-'a';
        cur.x=s1[1]-'1';
        ey=s2[0]-'a';
        ex=s2[1]-'1';
        ans=0;
        bfs();
        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,ans);
    }
    return 0;
}