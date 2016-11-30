#include<iostream>
using namespace std;
int main(){
    char c;
    int n,i,j;
    bool blank=false;
    while(cin>>c>>n,c!='@'){
        if(blank) printf("\n");
        blank=true;
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++) printf(" ");
            printf("%c",c);
            if(!i){
                printf("\n");
                continue;
            }
            for(j=0;j<2*i-1;j++) printf(" ");
            printf("%c\n",c);
        }
        for(i=0;i<2*n-1;i++) printf("%c",c);
        printf("\n");
    }
}