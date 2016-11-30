#include<iostream>
using namespace std;
long long C(long long n,long long m){
    long long ans=0,t=1,j=1;
    int i;
    for(i=n;i>=n-m+1;--i){
        t*=i;
    }
    for(i=2;i<=m;++i) j*=i;
    ans=t/j;
    return ans;
}
int main(){
    long long cp[14]={0,0,1},ans;
    int i,n;
    for(i=3;i<14;++i)
        cp[i]=(i-1)*(cp[i-1]+cp[i-2]);
    while(scanf("%d",&n)!=EOF,n){
        ans=1;
        for(i=2;i<=n/2;++i){
            ans+=cp[i]*C(n,i);
        }
        printf("%I64d\n",ans);
    }
    
}