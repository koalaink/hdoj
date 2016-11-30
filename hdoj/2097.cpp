#include<iostream>
using namespace std;
int main(){
    int n,c,c12,c16,temp;
    while(cin>>n,n){
        c=n%10+n/10%10+n/100%10+n/1000;
        c12=c16=0;temp=n;
        while(temp){
            c12+=temp%12;
            temp/=12;
        }
        temp=n;
        while(temp){
            c16+=temp%16;
            temp/=16;
        }
        if(c12==c && c16==c) cout<<n<<" is a Sky Number.\n";
        else cout<<n<<" is not a Sky Number.\n";
    }
}