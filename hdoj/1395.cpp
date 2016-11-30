#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    int n,x,i,t;
    while(scanf("%d",&n)!=EOF){
        t=1;
        for(i=1;i<5000;i++){
            t=t<<1;
            if(t%n==1){
                printf("2^%d mod %d = 1\n",i,n);
                break;
            }
            t=t%n;
        }
        if(i==5000) printf("2^? mod %d = 1\n",n);
    }
}