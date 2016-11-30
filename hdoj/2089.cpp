#include<iostream>
using namespace std;
int main(){
    bool a[1000001]={0};
    int i;
    for(i=1;i<1000000;i++){
        int t=i;
        while(t){
            if(t%10==4 || t%100==62){
                a[i]=true;
                break;
            }
            t/=10;
        }
        a[i]=!a[i];
    }
    int n,m,ans;
    while(scanf("%d%d",&n,&m)!=EOF,n||m){
        ans=0;
        for(i=n;i<=m;i++) if(a[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}