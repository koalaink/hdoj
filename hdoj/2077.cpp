#include<iostream>
using namespace std;
__int64 power(int n,int m){
    __int64 ans=1;
    while(m--) ans*=n;
    return ans;
}
int main(){
    __int64 hanoi[21]={0,1};
    int i,n,t;
    for(i=2;i<21;i++)
        hanoi[i]=hanoi[i-1]+power(3,i-1);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%I64d\n",hanoi[n-1]*2+2);
    }
}