/*
sample input:
2 3 1 2013
2 3 2 2013
2 2 1 2013
 */
#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

struct node{
    ll matrix[2][2];
    node(ll a=0,ll b=0,ll c=0,ll d=0){
        matrix[0][0]=a;
        matrix[0][1]=b;
        matrix[1][0]=c;
        matrix[1][1]=d;
        return ;
    }
};

node mul(node a,node b,ll m){
    node ans(0,0,0,0);
    for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k){
        ans.matrix[i][j]=(ans.matrix[i][j]+a.matrix[i][k]*b.matrix[k][j])%m;
    }
    return ans;
}

int main(){
    ll a,b,n,m;
    // freopen("0input.txt","r",stdin);
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&m)!=EOF){
        ll p=2*a;
        ll q=b-a*a;
        node base(p,1,q,0);
        node ans(p,2,0,0);
        if(!n){ printf("1\n");continue;}
        while(n){
            if(n&1){
                ans=mul(ans,base,m);
            }
            n>>=1;
            base=mul(base,base,m);
        }
        printf("%I64d\n",(ans.matrix[0][1]+m)%m);
    }
    return 0;
}