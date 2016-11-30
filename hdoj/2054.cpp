#include<iostream>
#include<string>
using namespace std;
int main(){
    string change(string);
    string a,b;
    while(cin>>a>>b){
        a=change(a);b=change(b);
        if(a==b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
string change(string a){
    int point=0;
    int i=0;
    while(a[0]=='0') a.erase(0,1);
    while(i<a.size()){
        if(a[i]=='.') point=1;
        i++;
    }
    if(point){
        while(a[a.size()-1]=='0') a.erase(a.size()-1,1);
        if(a[a.size()-1]=='.') a.erase(a.size()-1,1);
    }
    return a;
}

