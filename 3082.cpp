#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    int t,n,len,i,j;
    double ans,r[20],temp;
    char line[100];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(r,0,sizeof(r));
        for(i=0;i<n;i++){
            scanf("%s",line);
            len=strlen(line);
            for(j=0;j<len;j++){
                if(line[j]=='-') continue;
                temp=0;
                while(line[j]!='-'){
                    temp=temp*10+line[j]-'0';
                    j++;
                }
                r[i]+=temp;
            }
        }
        ans=0;
        temp=1;
        for(i=0;i<n;i++){
            temp*=r[i];
        }
        for(i=0;i<n;i++)
            ans+=temp/r[i];
        ans=temp/ans;
        printf("%.2f\n",ans);
    }
}