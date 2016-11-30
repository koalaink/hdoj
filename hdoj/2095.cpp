#include<iostream>
#include<map>
using namespace std;
int main(){
    int n,p;
    map<int,int> present;
    while(scanf("%d",&n)!=EOF,n){
        while(n--){
            scanf("%d",&p);
            present[p]++;
            
        }
        map<int,int>::iterator it=present.begin();
        while(it!=present.end() && it->second!=1 ) it++;
        printf("%d\n",it->first);
        present.clear();
    }
}