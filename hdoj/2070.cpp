#include<iostream>
using namespace std;
int main(){
    __int64 f[51]={0,1};
    int i;
    for(i=2;i<51;i++) f[i]=f[i-1]+f[i-2];
    while(scanf("%d",&i)!=EOF && i!=-1)
        printf("%I64d\n",f[i]);
}