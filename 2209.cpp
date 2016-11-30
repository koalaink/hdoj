#include<iostream>
#include<string>
#include<queue>
using namespace std;

const int MAX=1100000;
char zp[30];
int len,vis[MAX],ans[MAX];

int bfs(int x){
    queue<int> q;
    if(x==0) return 0;
    q.push(x);vis[x]=1;ans[x]=0;
    while(!q.empty()){
        x=q.front();q.pop();
        for(int i=1;i<=len;i++){
            int nx;
            if(i==1) nx=x^3;
            else nx=x^(7<<i-2);
            nx&=(1<<len)-1;
            if(vis[nx]) continue;
            vis[nx]=1;ans[nx]=ans[x]+1;
            if(nx==0) return ans[nx];
            q.push(nx);
        }
    }
    return -1;
}

int main(){
    while(scanf("%s",zp)!=EOF){
        len=strlen(zp);
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        int i,t=0;
        for(i=0;i<len;i++)
            t=t*2+zp[i]-'0';
        i=bfs(t);
        if(i<0) printf("NO\n");
        else printf("%d\n",i);
    }
    return 0;
}