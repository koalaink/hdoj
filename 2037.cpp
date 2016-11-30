#include<iostream>
int main(){
    int n,i,j,ans,temp;
    int s[100],e[100];
    while(scanf("%d",&n)!=EOF,n){
        for(i=0;i<n;i++)
            scanf("%d%d",s+i,e+i);
        for(i=1;i<n;i++)
            for(j=0;j<n-i;j++)
                if(e[j]>e[j+1]){
                    temp=e[j];e[j]=e[j+1];e[j+1]=temp;
                    temp=s[j];s[j]=s[j+1];s[j+1]=temp;
                }
        ans=1;
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                if(s[j]>=e[i]){
                    ans++;
                    i=j-1;
                    break;
                }
        printf("%d\n",ans);
    }
}