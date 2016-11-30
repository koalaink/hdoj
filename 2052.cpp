#include<iostream>
int main(){
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<m+2;i++){
            for(j=0;j<n+2;j++){
                if(i==0&&j==0 || i==m+1&&j==0 || i==0&&j==n+1 || i==m+1&&j==n+1) printf("+");
                else if(i==0 || i==m+1) printf("-");
                else if(j==0 || j==n+1) printf("|");
                else printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
}