#include<iostream>
using namespace std;
int main(){
    int n,i,temp,sum;
    while(cin>>n,n){
        sum=0;
        for(i=0;i<n;i++){
            cin>>temp;
            sum+=temp;
        }
        cout<<sum<<endl;
    }
}