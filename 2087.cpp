#include<iostream>
#include<string>
using namespace std;
int main(){
    string a,b;
    int index,ans;
    while(cin>>a>>b,a!="#"){
        index=0;ans=0;
        while(index<a.size()){
            if(a.substr(index,b.size()).compare(b)==0){
                index+=b.size();
                ans++;
                continue;
            }
            index++;
        }
        printf("%d\n",ans);
    }
    return 0;
}