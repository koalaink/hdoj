#include<iostream>
using namespace std;
main(){
    int n,a[1000],i,p,temp;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        p=a[0];
        for(i=1;i<n;i++){
            temp=p;
            while(p%a[i]) p+=temp;
        }
        cout<<p<<endl;
    }
}