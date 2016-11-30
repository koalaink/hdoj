#include<iostream>
int main(){
    double f[51]={1,1,2};
    int i,n;
    for(i=3;i<51;i++) f[i]=f[i-1]+f[i-2];
    while(scanf("%d",&n)!=EOF){
        printf("%.0lf\n",f[n]);
    }
}