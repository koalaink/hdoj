#include<iostream>
#include<stdio.h>
using namespace std;
int c[1005][1005];
int main(){
    int i,j,n;
    memset(c,0,sizeof(c));
    c[0][1]=1;
    for(i=1;i<1005;i++){
        for(j=1;j<1005;j++){
            if(j>1) c[i][j]+=c[i-1][j]*2;
            else c[i][j]+=c[i-1][j]*2+1;
        }
        for(j=2;j<1005;j++){
            if(c[i][j-1]>9)
                c[i][j]+=c[i][j-1]/10;
            c[i][j-1]%=10;
        }
    }
    while(scanf("%d",&n)!=EOF){
        i=1004;
        while(i>=1 && c[n][i]==0){
            i--;
        }
        for(;i>=1;i--){
            printf("%d",c[n][i]);
        }
        printf("\n");
    }
    return 0;
}