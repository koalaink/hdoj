#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    int i;char max;
    while(cin>>s){
        for(i=0;i<s.size();i++){
            if(!i){max=s[i];continue;}
            if(s[i]>max) max=s[i];
        }

        for(i=0;i<s.size();i++){
            cout<<s[i];
            if(s[i]==max) cout<<"(max)";
        }
        cout<<endl;
    }
}