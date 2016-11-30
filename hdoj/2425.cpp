#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

const int MAX=25;
char map[MAX][MAX];
bool mark[MAX][MAX];
int R,C,sr,sc,tr,tc,vp,vs,vt,ans;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

struct Node{
    int r;
    int c;
    int step;
    friend bool operator<(const Node& a,const Node& b){
        return a.step>b.step;
    }
};

bool check(const Node& a){
    if(a.r>=0 && a.r<R && a.c>=0 && a.c<C && map[a.r][a.c]!='@')
        return true;
    return false;
}

void bfs(){
    priority_queue<Node> q;
    Node now,next;
    now.c=sc;
    now.r=sr;
    now.step=0;
    q.push(now);
    while(!q.empty()){
        now=q.top();q.pop();
        if(now.r==tr && now.c==tc){
            ans=now.step;
            return ;
        }
        for(int i=0;i<4;i++){
            next.r=now.r+dir[i][0];
            next.c=now.c+dir[i][1];
            next.step=now.step;
            if(check(next) && !mark[next.r][next.c]){
                mark[next.r][next.c]=true;
                if(map[next.r][next.c]=='#') next.step+=vp;
                else if(map[next.r][next.c]=='.') next.step+=vs;
                else next.step+=vt;
                q.push(next);
            }
        }
    }
    return ;
}

int main(){
    int text=1;
    while(scanf("%d%d",&R,&C)!=EOF){
        scanf("%d%d%d",&vp,&vs,&vt);
        int i,j;
        for(i=0;i<R;i++){
            char temp[MAX];
            scanf("%s",temp);
            for(j=0;j<C;j++)
                map[i][j]=temp[j];
        }
        scanf("%d%d%d%d",&sr,&sc,&tr,&tc);
        memset(mark,false,sizeof(mark));
        ans=0xffffff;
        bfs();
        printf("Case %d: ",text++);
        ans==0xffffff?printf("-1\n"):printf("%d\n",ans);
    }
}