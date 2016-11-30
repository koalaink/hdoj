#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int t;
    int n,sum;
    double p;
    int money[105];
    double f[10005];
    double risk[105];
    scanf("%d",&t);
    while(t--){
        scanf("%lf%d",&p,&n);
        p=1-p;
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d%lf",&money[i],&risk[i]);
            sum+=money[i];
            risk[i]=1-risk[i];
        }
        for(int i=0;i<=sum;i++) f[i]=0;
        f[0]=1;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=money[i];j--){
                f[j]=(f[j]>(f[j-money[i]]*risk[i]))?f[j]:(f[j-money[i]]*risk[i]);
            }
        }
        for(int i=sum;i>=0;i--){
            if(f[i]-p>0.000000001){
                printf("%d\n",i);
                break;
            }
        }
    }
}