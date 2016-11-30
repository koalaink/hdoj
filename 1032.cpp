#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int min,max,ans,num,tmp,i;
    while(scanf("%d%d",&min,&max)!=EOF){
        printf("%d %d",min,max);
        if(min>max) min=min^max,max=min^max,min=min^max;
        for(i=min,ans=1;i<=max;i++){
            tmp=i;
            num=1;
            while(tmp!=1){
                tmp=(tmp&1)==1?tmp*3+1:tmp>>1;
                num++;
            }
            if(num>ans) ans=num;
        }
        printf(" %d\n",ans);
    }
    return 0;
}