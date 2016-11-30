/*
sample input:
123456789 3
21 1
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

const int MAX=35;
char s1[MAX];
int ans;
long long n;
int len;

void dfs(int index,long long sum){
    if(index==len){
        if(sum==n) ans++;
        return ;
    }
    long long tmp=0;
    for(int i=index;i<len;++i){
        tmp=tmp*10+s1[i]-'0';
        dfs(i+1,sum+tmp);
        if(index>0) dfs(i+1,sum-tmp);
    }
    return ;
}

int main(){
    // freopen("0input.txt","r",stdin);
    while(scanf("%s%I64d",s1,&n)!=EOF){
        ans=0;
        len=strlen(s1);
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}