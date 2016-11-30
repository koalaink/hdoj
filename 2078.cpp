#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a[40],i,t,n,m,min;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++) scanf("%d",a+i);
        min=a[0];
        for(i=1;i<n;i++) if(min>a[i]) min=a[i];
        printf("%d\n",(100-min)*(100-min));
    }
}