#include<iostream>
using namespace std;
int main(){
    int hi[50],n,i,sum,average;
    bool blank=false;
    while(scanf("%d",&n)!=EOF,n){
        if(blank) printf("\n");
        blank=true;
        sum=0;
        for(i=0;i<n;i++){
            scanf("%d",hi+i);
            sum+=hi[i];
        }
        average=sum/n;
        sum=0;
        for(i=0;i<n;i++)
            if(hi[i]>average)
                sum+=hi[i]-average;
        printf("%d\n",sum);
    }
    return 0;
}