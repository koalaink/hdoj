#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX=21;
int sticks[MAX];
bool mark[MAX];
bool flag;
int n,sum,a;

bool cmp(const int& a,const int& b){
    return a>b;
}

bool dfs(int index,int len,int num){
    if(num==3) return true;
    for(int i=index;i<n;i++){
        if(!mark[i]){
            mark[i]=true;
            if(len+sticks[i]<a && dfs(i+1,len+sticks[i],num))
                return true;
            else if(len+sticks[i]==a && dfs(0,0,num+1))
                return true;
            mark[i]=false;
        }
    }
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",sticks+i);
            sum+=sticks[i];
        }
        sort(sticks,sticks+n,cmp);
        memset(mark,false,sizeof(mark));
        if(sum%4==0 && sticks[0]<=sum/4){
            a=sum/4;
            if(dfs(0,0,0)) printf("yes\n");
            else printf("no\n");
        }else printf("no\n");
    }
    return 0;
}