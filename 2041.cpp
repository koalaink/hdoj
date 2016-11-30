#include<iostream>

using namespace std;

int main(){
    int n,i,m;
    int sum[40]={0,1,2};
    for(i=3;i<40;i++)
        sum[i]=sum[i-1]+sum[i-2];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        cout<<sum[m-1]<<endl;
    }
}