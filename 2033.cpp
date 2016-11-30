#include<iostream>

using namespace std;

int main(){
    int n,i;
    cin>>n;
    int h[3],m[3],s[3];
    for(i=0;i<n;i++){
        cin>>h[0]>>m[0]>>s[0]>>h[1]>>m[1]>>s[1];
        int temp=0;
        s[2]=(s[0]+s[1])%60;
        temp=(s[0]+s[1])/60;
        m[2]=(m[0]+m[1]+temp)%60;
        temp=(m[0]+m[1]+temp)/60;
        h[2]=(h[0]+h[1]+temp);
        cout<<h[2]<<" "<<m[2]<<" "<<s[2]<<endl;
    }
}