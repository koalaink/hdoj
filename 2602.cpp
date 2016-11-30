#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int n,v;
int pack[1001];

struct bone{
    int val;
    int vol;
}bones[1001];

int max(int a,int b){
    if(a>b) return a;
    return b;
}

void package(int value,int volume){
    for(int i=v;i>=volume;i--){
        pack[i]=max(pack[i],pack[i-volume]+value);
    }
}

int main(){
    int T,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&v);
        for(i=0;i<n;i++)
            scanf("%d",&bones[i].val);
        for(i=0;i<n;i++)
            scanf("%d",&bones[i].vol);
        memset(pack,0,sizeof(pack));
        for(i=0;i<n;i++)
            package(bones[i].val,bones[i].vol);
        printf("%d\n",pack[v]);
    }
}