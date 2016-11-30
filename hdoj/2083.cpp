#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
    return a<b;
}

int main(){
    int t,a[501],n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
        }
        sort(a,a+n,cmp);
        int ans=0;
        if(n%2==0)
            for(int i=n/2;i<n;i++)
                ans+=a[i]-a[n-i-1];
        else
            for(int i=n/2+1;i<n;i++)
                ans+=a[i]-a[n-i-1];
        printf("%d\n",ans);
    }
}