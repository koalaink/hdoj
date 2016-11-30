#include<iostream>
using namespace std;
int main(){
    int n,a,i;
    char ans[12];
    scanf("%d",&n);
    while(n--){
        scanf("%s",ans);
        printf("6%s\n",ans+6);
    }
}