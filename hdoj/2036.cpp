#include<iostream>
int main(){
    int n,i,x[100],y[100];
    double sum;
    while(scanf("%d",&n)!=EOF,n){
        for(i=0;i<n;i++) scanf("%d%d",x+i,y+i);
        sum=0;
        for(i=0;i<n-1;i++) sum+=x[i]*y[i+1]-x[i+1]*y[i];
        sum+=x[i]*y[0]-x[0]*y[i];
        printf("%.1lf\n",sum/2);
    }
}