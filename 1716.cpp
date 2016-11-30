#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;

int card[6];
bool used[6],flag;
set<int>s;

void dfs(int num,int index){
    if(index==4){
        s.insert(num);
        return ;
    }
    for(int i=1;i<=4;i++){
        if(!used[i]){
            used[i]=true;
            dfs(num*10+card[i],index+1);
            used[i]=false;
        }
    }
    return ;
}

int main(){
    int a,b;
    bool n_first_t=false,n_first_c=false;
    while(scanf("%d%d%d%d",card+1,card+2,card+3,card+4),card[1]||card[2]||card[3]||card[4]){
        if(n_first_t) printf("\n");
        n_first_t=true;
        s.clear();
        for(int i=1;i<=4;i++){
            used[i]=true;
            dfs(card[i],1);
            used[i]=false;
        }
        set<int>::iterator it=s.begin();
        while(*it<1000 && it!=s.end() ) it++;
        printf("%d",*it);
        a=*it/1000;
        it++;
        for(;it!=s.end();it++){
            if(*it/1000!=a){
                a=*it/1000;
                printf("\n%d",*it);
            }else printf(" %d",*it);
        }
        printf("\n");
    }
}