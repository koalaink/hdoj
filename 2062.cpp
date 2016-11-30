#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int i,n,temp;
    __int64 m;
    __int64 f[21]={0};
    int s[21];
    for(i=1;i<21;i++)
        f[i]=f[i-1]*(i-1)+1;
    while(scanf("%d%I64d",&n,&m)!=EOF){
        for(i=0;i<21;i++)
            s[i]=i;
        while(n>0 && m>0 ){
            temp=m/f[n]+(m%f[n]>0?1:0);
            if(temp>0){
                printf("%d",s[temp]);
                for(i=temp;i<=n;i++) s[i]=s[i+1];
                m-=((temp-1)*f[n]+1);
                putchar(m==0?'\n':' ');
            }
            n--;
        }
    }
    return 0;
}