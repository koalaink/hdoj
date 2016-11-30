#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int t,n,m,text,count;
    scanf("%d",&t);
    while(t--){
        text=1;
        while(scanf("%d%d",&n,&m),m||n){
            count=0;
            for(int i=1;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if((i*i+j*j+m)%(i*j)==0)
                        count++;
                }
            }
            printf("Case %d: %d\n",text++,count);
        }
        if(t!=0) printf("\n");
    }
}