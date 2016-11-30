#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

bool cmp(const int& a,const int& b){
    return a<b;
}

int main(){
    int c,n,i,a[11];
    while(scanf("%d",&c)!=EOF){
        while(c--){
            scanf("%d",&n);
            for(i=0;i<n;i++) scanf("%d",a+i);
            sort(a,a+n,cmp);
            printf("%d\n",a[1]);
        }
    }
}