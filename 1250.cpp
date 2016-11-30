#include<iostream>
const int MAX=7050;
const int S=506;
int f[MAX][S];
int main(){
    f[0][S-1]=f[1][S-1]=f[2][S-1]=f[3][S-1]=1;
    int a=0,i,j;
    for(i=4;i<MAX;++i){
        for(j=S-1;j>=0;--j){
            a+=f[i-1][j]+f[i-2][j]+f[i-3][j]+f[i-4][j];
            f[i][j]=a%10000;
            a/=10000;
        }
    }
    int n;
    while(scanf("%d", &n)==1){
        int j=0;
        while(f[n-1][j]==0)
            j++;
        printf("%d", f[n-1][j++]);
        for(; j<S; j++)
            printf("%04d", f[n-1][j]);
        putchar('\n');
    }
}