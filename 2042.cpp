#include<iostream>
using namespace std;
int main(){
    int n,sheep[31]={3},i,a;
    for(i=1;i<31;i++) sheep[i]=(sheep[i-1]-1)*2;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        printf("%d\n",sheep[a]);
    }
}