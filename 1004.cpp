#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n,i;
    map<string,int> color;
    vector<string> balloon;
    while(cin>>n,n){
        for(i=0;i<n;i++){
            string str;
            cin>>str;
            color[str]++;
            if(color[str]<0) color[str]=1;
        }
        map<string,int>::iterator iter=color.begin();
        int max=iter->second;string balloonT=iter->first;
        for(;iter!=color.end();iter++){
            if(iter->second >max ){
                max=iter->second;balloonT=iter->first;
            }
        }
        balloon.push_back(balloonT);
        color.clear();
    }
    for(i=0;i<balloon.size();i++){
        cout<<balloon[i]<<endl;
    }
    
}