#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int t=1;
    int n,h[55],ah,ans;
    while(scanf("%d",&n),n){
        ah=0;
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",h+i);
            ah+=h[i];
        }
        ah/=n;
        for(int i=0;i<n;i++){
            if(h[i]>ah) ans+=h[i]-ah;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",t++,ans);
    }
}