#include<iostream>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        bool capslock=false;
        scanf("%d",&n);
        char *output=new char[n+1];
        char ch;int i=0;
        while(n--){
            cin>>ch;
            if(ch=='C'){
                capslock=!capslock;
                for(int y=0;y<3;y++) cin>>ch;
            }else if(ch=='S'){
                for(int x=0;x<5;x++) cin>>ch;
                if(capslock) output[i++]=ch;
                else output[i++]=(char)(ch-'a'+'A');
            }else{
                if(capslock) output[i++]=(char)(ch-'a'+'A');
                else output[i++]=ch;
            }
        }
        output[i]='\0';
        cout<<output<<endl;
    }
}