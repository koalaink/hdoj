#include<iostream>
using namespace std;
int main(){
    char d[2];
    int n,t,i,j,c;
    bool first=0;
    while(cin>>n){
        if((n/2)%2) cin>>d[0]>>d[1];
        else cin>>d[1]>>d[0];
        if(first) printf("\n");
        first=true;
        if(n==1){
            printf("%c\n",d[1]);
            continue;
        }
        for(c=1;c<=n;++c){
            for(j=1;j<=n;++j){
                if(c<=n/2+1) i=c;
                else i=n-c+1;
                if(i==j &&(i==1 || i== n) || i==1&&j==n || i==n&&j==1){
                    printf(" ");
                    continue;
                }
                if(j>=i && j<=n-i ) printf("%c",d[i%2]);
                else printf("%c",d[j%2]);
            }
            printf("\n");
        }
    }
}