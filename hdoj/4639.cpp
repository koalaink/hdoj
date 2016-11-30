/*
sample input:
4
wanshangniyoukongme
womenyiqichuqukanxingxingba
bulehehewohaiyoushi
eheheheh
 */
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define MAX 5045
using namespace std;

int fb[MAX];

int main(){
    int t,cas=1;
    char s1[MAX*2];
    memset(fb,0,sizeof(fb));
    fb[0]=fb[1]=1;
    for(int i=2;i<MAX;++i) fb[i]=(fb[i-1]+fb[i-2])%10007;
    // freopen("0input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        int ans=1;
        scanf("%s",s1);
        int len=strlen(s1);
        for(int i=0;i<len;++i){
            int tmp=0;
            while(i+1<len&&s1[i]=='h'&&s1[i+1]=='e') tmp++,i+=2;
            ans=(ans*fb[tmp])%10007;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}