#include<iostream>
using namespace std;
int main(){
    int n,count,i,j;
    int ss[10001]={0};
    for(i=2;i<=5000;i++){
        for(j=2;j*i<=10000;j++){
            if(ss[j*i]==1) continue;
            ss[j*i]=1;
        }
    }
    while(cin>>n,n){
        count=0;
        for(int k=2;k<=n/2;k++){
            if(ss[k]==0 && ss[n-k]==0 && n!=k*2 ) count++;
        }
        cout<<count<<endl;
    }
}