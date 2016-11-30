#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX=55;
char map[MAX][MAX];
bool vis[MAX][MAX];
int dir[4][2]={1,0,-1,0,0,1,0,-1};    // down up right left
int m,n,ans;

struct node{
    int x,y;
    bool dir[4];
    bool check(){
        if(x>=0&&x<m&&y>=0&&y<n)
            return true;
        return false;
    }
    void getdir(){
        char t=map[x][y];
        switch(t){
        case 'A':
            dir[0]=false;
            dir[1]=true;
            dir[2]=false;
            dir[3]=true;
            break;
        case 'B':
            dir[0]=false;
            dir[1]=true;
            dir[2]=true;
            dir[3]=false;
            break;
        case 'C':
            dir[0]=true;
            dir[1]=false;
            dir[2]=false;
            dir[3]=true;
            break;
        case 'D':
            dir[0]=true;
            dir[1]=false;
            dir[2]=true;
            dir[3]=false;
            break;
        case 'E':
            dir[0]=true;
            dir[1]=true;
            dir[2]=false;
            dir[3]=false;
            break;
        case 'F':
            dir[0]=false;
            dir[1]=false;
            dir[2]=true;
            dir[3]=true;
            break;
        case 'G':
            dir[0]=false;
            dir[1]=true;
            dir[2]=true;
            dir[3]=true;
            break;
        case 'H':
            dir[0]=true;
            dir[1]=true;
            dir[2]=false;
            dir[3]=true;
            break;
        case 'I':
            dir[0]=true;
            dir[1]=false;
            dir[2]=true;
            dir[3]=true;
            break;
        case 'J':
            dir[0]=true;
            dir[1]=true;
            dir[2]=true;
            dir[3]=false;
            break;
        case 'K':
            dir[0]=true;
            dir[1]=true;
            dir[2]=true;
            dir[3]=true;
            break;
        }
    }
};

void dfs(const node& s){
    node next;
    for(int i=0;i<4;i++){
        if(s.dir[i]){
            next.x=s.x+dir[i][0];
            next.y=s.y+dir[i][1];
            if(next.check() && !vis[next.x][next.y]){
                next.getdir();
                if((i==0&&next.dir[1])||(i==1&&next.dir[0])||(i==2&&next.dir[3])||(i==3&&next.dir[2])){
                    vis[next.x][next.y]=true;
                    dfs(next);
                }
            }
        }
    }
    return ;
}

int main(){
    node s;
    while(scanf("%d%d",&m,&n),m>=0&&n>=0){
        for(int i=0;i<m;i++){
            char temp[MAX];
            scanf("%s",temp);
            for(int j=0;j<n;j++)
                map[i][j]=temp[j];
        }
        memset(vis,false,sizeof(vis));
        ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    vis[i][j]=true;
                    ans++;
                    s.x=i;s.y=j;
                    s.getdir();
                    dfs(s);
                }
            }
        }
        printf("%d\n",ans);
    }
}
