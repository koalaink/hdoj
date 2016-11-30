#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct node{
    int s,t;
    void init(){
        s=s/2+(s&1?1:0);
        t=t/2+(t&1?1:0);
        if(s>t){
            s=s^t;
            t=s^t;
            s=s^t;
        }
    }
};

bool cmp(node& a,node& b){
    return a.s<b.s;
}

int main(){
    node table[205];
    bool done[205],flag;
    int T,n,i,ans,to;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&table[i].s,&table[i].t);
            table[i].init();
        }
        sort(table,table+n,cmp);
        memset(done,false,sizeof(done));
        ans=0;
        while(1){
            i=0;
            while(done[i] && i<n) i++;
            if(i==n) break;
            to=table[i].t;
            done[i]=true;
            for(;i<n;i++){
                if(done[i]) continue;
                if(table[i].s>to){
                    to=table[i].t;
                    done[i]=true;
                }
            }
            ans+=10;
        }
        printf("%d\n",ans);
    }
}

