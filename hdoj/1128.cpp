#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    int i,j,k;
    bool sn[1000001];
    memset(sn,true,sizeof(sn));
    for(i=1;i<1000001;i++){
        if(sn[i])
            printf("%d\n",i);
        j=k=i;
        while(j){
            k+=j%10;
            j/=10;
        }
        if(k<1000001){
            sn[k]=false;
        }
    }
}