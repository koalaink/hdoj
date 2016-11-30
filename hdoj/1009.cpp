#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct node{
    double j,f;
};

bool cmp(node& a,node& b){
    return a.j/a.f>b.j/b.f;
}

int main(){
    node gate[1001];
    int m,n,i,j;
    double ans;
    while(scanf("%d%d",&m,&n),m!=-1 && n!=-1){
        for(i=0;i<n;i++) scanf("%lf%lf",&gate[i].j,&gate[i].f);
        sort(gate,gate+n,cmp);
        ans=0;
        for(i=0;i<n;i++){
            if(m>=gate[i].f){
                ans+=gate[i].j;
                m-=gate[i].f;
            }else{
                ans+=(m/gate[i].f*gate[i].j);
                break;
            }
        }
        printf("%.3lf\n",ans);
    }
}

