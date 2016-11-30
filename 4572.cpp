/*
sample input:
3 3
3 5
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int ans;
    int n , m ;
    while(scanf("%d%d",&m,&n)!=EOF){
        ans=0;
        for(int i=2;i<n;i+=2)
            ans+=2*m--;
        ans+=m;
        printf("%d\n",ans);
    }
    return 0 ;
}