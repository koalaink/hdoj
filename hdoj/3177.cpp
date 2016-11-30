#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct things{
    int a,b;
};

bool cmp(things& x,things& y){
    if((x.b-x.a)!=(y.b-y.a)) return (x.b-x.a)>(y.b-y.a);
    if(x.b!=y.b) return x.b>y.b;
    return x.a<y.a;
}

int main(){
    things ab[1005];
    int t,i,av;
    int v,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&v,&n);
        av=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&ab[i].a,&ab[i].b);
            av+=ab[i].a;
        }
        if(av>v){
            printf("No\n");
            continue;
        }
        sort(ab,ab+n,cmp);
        for(i=0;i<n;i++){
            if(v<ab[i].b) break;
            v-=ab[i].a;
        }
        if(i==n) printf("Yes\n");
        else printf("No\n");
    }
}