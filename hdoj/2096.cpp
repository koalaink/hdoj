#include<iostream>
using namespace std;
int main(){
    int n,i,a[2];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[0]>>a[1];
        cout<<(a[0]%100+a[1]%100)%100<<endl;
    }
}