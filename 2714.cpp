#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(){
    string s;
    int i,j,ans,mark;
    while(cin>>s){
        j=10;
        ans=0;
        for(i=0;i<10;i++){
            if(s[i]=='?'){
                mark=j;
                j--;
                continue;
            }
            if(s[i]=='X'){
                ans+=10;
                j--;
                continue;
            }
            ans+=(int)(s[i]-'0')*j;
            j--;
        }
        if((ans+10)%11==0 && mark==1){
            puts("X");
        }else{
            for(i=0;i<=9;i++){
                if((mark*i+ans)%11==0){
                    printf("%d\n",i);
                    break;
                }
            }
            if(i==10) printf("-1\n");
        }
    }
}