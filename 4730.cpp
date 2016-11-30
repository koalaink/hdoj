#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    char key[]="desu";
    string s;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        bool flag=false;
        for(int j=0;j<4;j++)
            if(s[s.size()-4+j]!=key[j]) flag=true;
        printf("Case #%d: ",i);
        if(flag){
            cout<<s<<"nanodesu"<<endl;
        }else{
            for(int j=0;j<s.size()-4;j++)
                cout<<s[j];
            cout<<"nanodesu"<<endl;
        }
    }
}