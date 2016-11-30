#include<iostream>
#include<string>
using namespace std;
int main(){
    int m,i;
    bool N=0,C=0,LL=0,CL=0;
    string password;
    cin>>m;
    while(m--){
        N=C=LL=CL=0;
        cin>>password;
        if(password.size()<8 || password.size()>16 ){
            cout<<"NO"<<endl;
            continue;
        }
        for(i=0;i<password.size();i++){
            if(password[i]>='0' && password[i]<='9') N=1;
            else if(password[i]>='a' && password[i]<='z') LL=1;
            else if(password[i]>='A' && password[i]<='Z') CL=1;
            else C=1;
        }
        if(N+C+LL+CL>=3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}