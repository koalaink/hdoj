#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    double pri,min;
    int t,n,vol,temp,maxv;
    char name[101],ans[101];
    cin>>t;
    while(t--){
        min=0xffffff;
        maxv=0;
        cin>>n;
        while(n--){
            cin>>name>>pri>>vol;
            temp=vol/200;
            if(temp==0) continue;
            if(temp>5) temp=5;
            pri=pri/temp;
            if(pri<min){
                min=pri;
                strcpy(ans,name);
                maxv=vol;
            }else if(pri==min){
                if(vol>maxv){
                    strcpy(ans,name);
                    maxv=vol;
                }
            }
        }
        cout<<ans<<endl;
    }
}