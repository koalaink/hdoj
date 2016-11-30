#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    int n,sum;
    string s1,s2;
    map<string,int> a,l;
    while(scanf("%d",&n)!=EOF,n){
        while(n--){
            cin>>s1>>s2;
            if(l[s1]==0) a[s1]=1;
            a[s2]=0;l[s2]=1;
        }
        sum=0;
        map<string,int>::iterator it;
        for(it=a.begin();it!=a.end();it++){
            if(it->second==1) sum++;
        }
        if(sum!=1) printf("No\n");
        else printf("Yes\n");
        a.clear();l.clear();
    }
    return 0;
}