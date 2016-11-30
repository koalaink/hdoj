#include<iostream>
using namespace std;
int main(){
    int t,n,m;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&m,&n);
        printf("Case #%d: ",i);
        if(m==1){
            for(int j=0;j<n;j++)
                printf("a");
        }else if(m==2){
            if(n==1) printf("a");
            else if(n==2) printf("ab");
            else if(n==3) printf("aab");
            else if(n==4) printf("aabb");
            else if(n==5) printf("aaaba");
            else if(n==6) printf("aaabab");
            else if(n==7) printf("aaababb");
            else if(n==8) printf("aaababbb");
            else{
                printf("aaaab");
                n-=5;
                for(int j=0;j<n/6;j++)
                    printf("abbaab");
                n%=6;
                if(n==1) printf("a");
                else if(n==2) printf("ab");
                else if(n==3) printf("abb");
                else if(n==4) printf("abba");
                else if(n==5) printf("abbaa");
            }
        }else{
            for(int j=0;j<n/3;j++)
                printf("abc");
            n%=3;
            if(n==1) printf("a");
            else if(n==2) printf("ab");
        }
        printf("\n");
    }
}