#include<iostream>
#include<queue>
using namespace std;

const int MAX=11;
bool vis[MAX][MAX][MAX][MAX];
int start[4],key[4];

struct pw{
    int word[4];
    int step;
};

void bfs(){
    pw now,next;
    for(int i=0;i<4;i++)
        now.word[i]=start[i];
    now.step=0;
    vis[start[0]][start[1]][start[2]][start[3]]=true;
    queue<pw> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();q.pop();
        bool f=true;
        for(int i=0;i<4;i++)
            if(now.word[i]!=key[i]){
                f=false;
                break;
            }
        if(f){
            printf("%d\n",now.step);
            return ;
        }
        for(int i=0;i<4;i++){
            next=now;
            next.step++;
            next.word[i]++;
            if(next.word[i]==10) next.word[i]=1;
            if(!vis[next.word[0]][next.word[1]][next.word[2]][next.word[3]]){
                vis[next.word[0]][next.word[1]][next.word[2]][next.word[3]]=true;
                q.push(next);
            }
        }
        for(int i=0;i<4;i++){
            next=now;
            next.step++;
            next.word[i]--;
            if(next.word[i]==0) next.word[i]=9;
            if(!vis[next.word[0]][next.word[1]][next.word[2]][next.word[3]]){
                vis[next.word[0]][next.word[1]][next.word[2]][next.word[3]]=true;
                q.push(next);
            }
        }
        for(int i=0;i<3;i++){
            int temp;
            next=now;next.step++;
            temp=next.word[i];
            next.word[i]=next.word[i+1];
            next.word[i+1]=temp;
            if(!vis[next.word[0]][next.word[1]][next.word[2]][next.word[3]]){
                vis[next.word[0]][next.word[1]][next.word[2]][next.word[3]]=true;
                q.push(next);
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char t1[MAX],t2[MAX];
        scanf("%s%s",t1,t2);
        for(int i=0;i<4;i++){
            start[i]=t1[i]-'0';
            key[i]=t2[i]-'0';
        }
        memset(vis,0,sizeof(vis));
        bfs();
    }
}