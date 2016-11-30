/*
sample input:
3
10 3
1 2 3
0 1 2
100 7
3 4 5 6 7 8 9
1 2 3 4 5 6 7
10000 10
1 2 3 4 5 6 7 8 9 10
0 1 2 3 4 5 6 7 8 9
 */
#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

void Exgcd(ll n,ll m,ll& d,ll& x,ll& y){
    if(!m){ d=n;x=1;y=0;return ;}
    Exgcd(m,n%m,d,y,x);
    y -= (n/m)*x;
    return ;
}

ll n,m;
ll aa[15];
ll r[15];

void solve(){
    ll a,b,c;
    ll d,x0,y0;
    bool flag=true;
    for(ll i=1;i<m;++i){
        a=aa[0];
        b=aa[i];
        c=r[i]-r[0];
        Exgcd(a,b,d,x0,y0);
        if(c%d){ flag=false;break;}
        b/=d;
        x0=(x0*(c/d)%b+b)%b;
        r[0]=x0*aa[0]+r[0];
        aa[0]=aa[0]*aa[i]/d;
    }
    if(!flag){ puts("0");return ;}
    long long ans=0;
    if(r[0]<=n) ans=1+(n-r[0])/aa[0];
    if(ans&&!r[0]) --ans;
    printf("%I64d\n",ans);
    return ;
}

int main(){
    ll i;
    int t;
    // freopen("0input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        for(i=0;i<m;++i) scanf("%I64d",&aa[i]);
        for(i=0;i<m;++i) scanf("%I64d",&r[i]);
        solve();
    }
    return 0;
}