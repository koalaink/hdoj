#include <stdio.h>
int main(){
    int i,n,t[1000];
    while(scanf("%d",&n)!=EOF){
        for(i=0;n;i++){
            t[i]=n%2;
            n/=2;
        }
        while(i--){
            printf("%d",t[i]);
        }
        printf("\n");
    }
    return 0;
}