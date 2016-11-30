#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,i,j;
    char a[100];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        gets(a);
        int n=strlen(a),temp=1;
        char *p=a,*q=(a+n-1);
        for(j=0;j<n/2;j++,p++,q--)
            if(*p!=*q) temp=0;
        if(temp) cout<<"yes\n";
        else cout<<"no\n";
    }
}