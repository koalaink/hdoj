#include<iostream>
#include<map>
using namespace std;
int main(){
    char ch;
    int i;
    map<char,int> letter;
    ch='A';
    for(i=0;i<26;i++) letter[ch+i]=i+1;
    ch='a';
    for(i=0;i<26;i++) letter[ch+i]=-(i+1);
    int t;
    cin>>t;
    while(t--){
        cin>>ch>>i;
        cout<<letter[ch]+i<<endl;
    }
}