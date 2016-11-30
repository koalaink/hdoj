/*
sample input:
2
2
14 57
5 56
5
19 54 40 24 80
11 2 36 20 76
 */
#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

ll N;
ll mi[10];
ll ai[10];

void exgcd(ll a,ll b,ll& d,ll& x,ll& y){
    if(!b){ d=a;x=1;y=0;return ;}
    exgcd(b,a%b,d,y,x);
    y -= (a/b)*x;
    return ;
}

void solve(int cas){
    ll d,x,y;
    ll a,b,c;
    bool flag=true;
    for(ll i=1;i<N;++i){
        a=mi[0];
        b=mi[i];
        c=ai[i]-ai[0];
        exgcd(a,b,d,x,y);
        if(c%d){ flag=false;break;}
        b/=d;
        x=(x*(c/d)%b+b)%b;
        ai[0]=mi[0]*x+ai[0];
        mi[0]=mi[0]*mi[i]/d;
    }
    printf("Case %d: ",cas);
    if(!flag) puts("-1");
    else{
        ai[0]=(ai[0]==0)?(mi[0]):(ai[0]);
        printf("%I64d\n",ai[0]);
    }
    return ;
}

int main(){
    int t;
    int cas=1;
    // freopen("0input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&N);
        for(ll i=0;i<N;++i) scanf("%I64d",&mi[i]);
        for(ll i=0;i<N;++i) scanf("%I64d",&ai[i]);
        solve(cas++);
    }
    return 0;
}