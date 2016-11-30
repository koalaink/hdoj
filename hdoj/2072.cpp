#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    string s,word;
    int i;
    map<string,bool> t;
    while(getline(cin,s,'\n'),s!="#"){
        i=0;
        while(i<s.size()){
            if(s[i]!=' '){
                word.push_back(s[i]);
                ++i;
                continue;
            }
            if(!word.empty()) t[word]++;
            word.clear();
            ++i;
        }
        if(!word.empty()){
            t[word]++;
            word.clear();
        }
        printf("%d\n",t.size());
        t.clear();
    }
}