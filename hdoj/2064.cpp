#include<iostream>
int main(){
    int n,i;
    __int64 t,hn[36]={0};
    for(i=1,t=1;i<36;i++){ t*=3;hn[i]=t-1;}
    while(scanf("%d",&n)!=EOF) printf("%I64d\n",hn[n]);
}