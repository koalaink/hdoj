/*
sample input:
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5 
****@
*@@*@
*@**@
@@@*@
@@**@
0 0 
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
#define MAX 105
using namespace std;

int ans;
int n , m;
char matrix[MAX][MAX];
bool vis[MAX][MAX];
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,1,-1,1,1,-1,-1,-1};

bool check(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m&&matrix[x][y]=='@';
}

void dfs(int x,int y){
    for(int i=0;i<8;++i){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(check(xx,yy)&&!vis[xx][yy]){
            vis[xx][yy]=true;
            dfs(xx,yy);
        }
    }
    return ;
}

int main(){
    // freopen("0input.txt","r",stdin);
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<n;++i){
            char tmp[MAX];
            scanf("%s",tmp);
            for(int j=0;j<m;++j)
                matrix[i][j]=tmp[j];
        }
        ans=0;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]=='@'&&!vis[i][j]){
                    ans++;
                    vis[i][j]=true;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}