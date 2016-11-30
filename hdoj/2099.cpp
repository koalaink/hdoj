#include<iostream>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b,(a||b)){
        int m=(a*100)%b,temp=0;
        if(m) m=b-m;
        while(m<100){
            if(temp) {cout<<" ";}
            if(m>9) cout<<m;
            else cout<<"0"<<m;
            m+=b;
            temp=1;
        }
        cout<<endl;
    }
}