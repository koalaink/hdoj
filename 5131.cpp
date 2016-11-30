/*
sample input:
5
WuSong 12
LuZhishen 12
SongJiang 13
LuJunyi 1
HuaRong 15
5
WuSong
LuJunyi
LuZhishen
HuaRong
SongJiang
0
 */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <map>
using namespace std;

struct node{
    char name[55];
    int k;
};

int n,m;
char name[55];
node people[205];
map<string,int> index;
int rank[205][2];

bool cmp(const node& a,const node& b){
    if(a.k!=b.k) return a.k>b.k;
    return strcmp(a.name,b.name)<0;
}

void solve(){
    rank[0][0]=rank[0][1]=0;
    for(int i=1;i<=n;++i){
        if(people[i].k==people[i-1].k){
            rank[i][0]=rank[i-1][0];
            rank[i][1]=rank[i-1][1]+1;
        }
        else{
            rank[i][0]=i;
            rank[i][1]=1;
        }
    }
    return ;
}

int main(){
    // freopen("0input.txt","r",stdin);
    while(scanf("%d",&n),n){
        index.clear();
        for(int i=1;i<=n;++i) scanf("%s %d",people[i].name,&people[i].k);
        sort(people+1,people+n+1,cmp);
        for(int i=1;i<=n;++i){
            printf("%s %d\n",people[i].name,people[i].k);
            index[people[i].name]=i;
        }
        solve();
        scanf("%d",&m);
        while(m--){
            scanf("%s",name);
            int i=index[name];
            printf("%d",rank[i][0]);
            if(rank[i][1]!=1) printf(" %d",rank[i][1]);
            puts("");
        }
    }
    return 0;
}