#include<iostream>
using namespace std;
main()
{
    int a,b,r;
    while(cin>>a>>b,a||b){
        r=1;
        while(b--){
            r*=a;
            r%=1000;
        }
        cout<<r<<endl;
    }
}