#include<iostream>
using namespace std;
int main(){
    int t,lb,ss,os;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&lb,&ss,&os);
        if(lb>6) ss+=lb-6+(lb-6)*7+2+3+4+5+6+7;
        else{
            int s=7;
            while(lb--) ss+=s--;
        }
        if(ss>=os) printf("Yes\n");
        else printf("No\n");
    }
}