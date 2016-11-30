#include<iostream>
using namespace std;
int main(){
    int i,j,k,l,n,ans;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            printf("1\n");
            continue;
        }
        ans=0;
        for(i=0;i*50<=n;i++)
            for(j=0;i*50+j*25<=n;j++)
                for(k=0;i*50+j*25+k*10<=n;k++)
                    for(l=0;i*50+j*25+k*10+l*5<=n;l++)
                        if(i+j+k+l+n-i*50-j*25-k*10-l*5<=100)
                            ans++;
        printf("%d\n",ans);
    }
}