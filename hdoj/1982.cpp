#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    int c,i,j,len,temp;
    char p[10001];
    cin>>c;
    while(c--){
        cin>>p;
        len=strlen(p);
        temp=0;
        j=0;
        for(i=0;i<len;i++){
            if(p[i]>='0'&&p[i]<='9'){
                temp=temp*10+p[i]-'0';
            }else if(p[i]=='#'){
                if(temp){
                    printf("%c",'A'+temp-1);
                    temp=0;
                }
                printf(" ");
            }else if(p[i]=='-'){
                printf("%c",'A'+temp-1);
                temp=0;
            }
        }
        if(temp) printf("%c",'A'+temp-1);
        printf("\n");
    }
}