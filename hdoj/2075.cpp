#include<iostream>
int main(){
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        (a%b==0)?printf("YES\n"):printf("NO\n");
    }
}