#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int t,i;
    __int64 n;
    int d[]={4, 8,16,32,64,28,56,12,24,48,96,92,84,68,36,72,44,88,76,52};
    while(scanf("%d",&t),t){
        for(i=1;i<=t;i++){
            scanf("%I64d",&n);
            printf("Case %d: %d\n",i,n<3?(n<2?2:6):(d[(2*n-4)%20]+d[(n-3)%20])%100);
        }
        printf("\n");
    }
    return 0;
}