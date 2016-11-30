#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

const int MAX=55;
char map[MAX][MAX];
bool vis[MAX][MAX];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int index[15][2];
int dis[15][15];
int val[15];
bool flag[15];
int w,h,l,m,sx,sy,ex,ey,ans,sum;

struct node{
    int x,y,step;
    bool check(){
        if(x>=0 && x<h && y>=0 && y<w && map[x][y]!='*')
            return true;
        return false;
    }
};

/*
void getdis(){
    node sn,en;
    sn.step=en.step=0;
    for(int i=0;i<=m;i++){
        for(int j=i+1;j<=m+1;j++){
            sn.x=index[i][0];
            sn.y=index[i][1];
            en.x=index[j][0];
            en.y=index[j][1];
            dis[j][i]=dis[i][j]=bfs(sn,en);
        }
    }
}
*/
int bfs(int st,int end){
    memset(vis,false,sizeof(vis));
    queue<node> q;
    node now,next;
    now.x=index[st][0];
    now.y=index[st][1];
    now.step=0;
    vis[now.x][now.y]=true;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.step>l) return -1;
        if(now.step==l && (st!=0||end!=(m+1))) return -1;
        if(now.x==index[end][0] && now.y==index[end][1]){
            return now.step;
        }
        for(int i=0;i<4;i++){
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            next.step=now.step+1;
            if(next.check() && !vis[next.x][next.y]){
                vis[next.x][next.y]=true;
                q.push(next);
            }
        }
    }
    return -1;
}
void dfs(int pl,int money,int time){
    if(ans==sum || time>l) return ;
    if(pl==m+1){
        if(money>ans)
            ans=money;
        return ;
    }
    for(int i=1;i<=m+1;i++){
        if(!flag[i] && dis[pl][i]!=-1 ){
            flag[i]=true;
            dfs(i,money+val[i],time+dis[pl][i]);
            flag[i]=false;
        }
    }
    return ;
}

int main(){
    int t,i,j,k;
    bool blank=false;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        sum=0;
        scanf("%d%d%d%d",&w,&h,&l,&m);
        for(j=1;j<=m;j++){
            scanf("%d",val+j);
            sum+=val[j];
        }
        val[0]=val[m+1]=0;
        for(j=0;j<h;j++){
            char temp[MAX];
            scanf("%s",temp);
            for(k=0;k<w;k++){
                map[j][k]=temp[k];
                if(temp[k]=='@'){
                    index[0][0]=j;
                    index[0][1]=k;
                }else if(temp[k]=='<'){
                    index[m+1][0]=j;
                    index[m+1][1]=k;
                }else if(temp[k]>='A' && temp[k]<='J'){
                    index[temp[k]-'A'+1][0]=j;
                    index[temp[k]-'A'+1][1]=k;
                }
            }
        }
        if(blank) printf("\n");
        blank=true;
        printf("Case %d:\n",i);
        for(j=0;j<=m;j++){
            for(k=j+1;k<=m+1;k++){
                dis[j][k]=dis[k][j]=bfs(j,k);
            }
        }
        if(dis[0][m+1]==-1 || dis[0][m+1]>l){
            printf("Impossible\n");
            continue;
        }
        ans=0;
        memset(flag,false,sizeof(flag));
        flag[0]=true;
        dfs(0,0,0);
        printf("The best score is %d.\n",ans);
    }
    return 0;
}