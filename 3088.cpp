#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
using namespace std;

const int MAX=60000;
bool mark[MAX];
int len,ans,end1,end2;

struct node{
    int state;
    int step;
};

void bfs(int s){
    node now,next;
    queue<node> q;
    now.state=s;
    now.step=0;
    q.push(now);
    mark[s]=true;
    while(!q.empty()){
        now=q.front();q.pop();
        if(now.state==0 || now.state==end1 || now.state==end2){
            ans=now.step;
            return ;
        }
        int temp[15],tmp=now.state;
        for(int i=0;i<len;i++) temp[i]=tmp%3,tmp/=3;
        for(int i=0;i<len-1;i++){
            if(temp[i]==temp[i+1]) continue;
            next.state=0;
            if(temp[i]+temp[i+1]==1) tmp=2;
            else if(temp[i]+temp[i+1]==2) tmp=1;
            else tmp=0;
            for(int j=len-1;j>=0;j--)
                if(j!=i && j!=i+1 )
                    next.state=next.state*3+temp[j];
                else next.state=next.state*3+tmp;
            if(!mark[next.state]){
                mark[next.state]=true;
                next.step=now.step+1;
                q.push(next);
            }
        }
    }
    return ;
}

int main(){
    int t;
    int s;
    char tmp[15];
    scanf("%d",&t);
    while(t--){
        scanf("%s",tmp);
        len=strlen(tmp);
        s=end1=end2=0;
        for(int i=0;i<len;i++) s=s*3+((tmp[i]=='r')?0:(tmp[i]=='g'?1:2)),end1=end1*3+1,end2=end2*3+2;
        memset(mark,false,sizeof(mark));
        ans=-1;
        bfs(s);
        ans!=-1?printf("%d\n",ans):printf("No solution!\n");
    }
}