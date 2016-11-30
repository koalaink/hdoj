/*
sample input:
2
2
2 1
5 6
2
1 11
3 10
 */
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define MAX 100005
using namespace std;

int n;
struct node{
    int d,t;
};
node cel[MAX];

bool cmp(node a,node b){
    return a.t>b.t;
}

int main(){
    int t;
    int cas=1;
    // freopen("0input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%d%d",&cel[i].d,&cel[i].t);
        sort(cel,cel+n,cmp);
        int ans=-1;
        int max;
        int tmp=0;
        for(int i=0;i<n;++i){
            tmp+=cel[i].d;
            max=tmp+cel[i].t;
            ans=ans>max?ans:max;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}