#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int count=0;
        for(int i=2;i<=n/2;i++){
            if(!(n%i))
                count++;
        }
        count+=2;
        if(n==1) count=1;
        if(count%2) cout<<1<<endl;
        else cout<<0<<endl;
    }
}