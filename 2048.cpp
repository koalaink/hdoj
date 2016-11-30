#include<iostream>
int main(){
    double ans[21]={0,0,1},jc[21]={1,1};
    int i,c,n;
    for(i=2;i<21;i++) jc[i]=jc[i-1]*i;
    for(i=3;i<21;i++) ans[i]=(i-1)*(ans[i-1]+ans[i-2]);
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        printf("%.2lf%%\n",ans[n]*100/jc[n]);
    }
}