#include<iostream>
#include<cmath>
int main(){
    int n,m,x,x1,x2;
    while(scanf("%d%d",&n,&m)!=EOF && (n||m)){
        if(n*n-4*m<0){
            printf("No\n");
            continue;
        }
        x=(int)sqrt((double)n*n-4*m);
        x1=(int)(n+(int)sqrt((double)n*n-4*m));
        x2=(int)(n-(int)sqrt((double)n*n-4*m));
        if(x*x==n*n-4*m)
            if(x1%2==0 && x2%2==0) printf("Yes\n");
            else printf("No\n");
        else printf("No\n");
    }
}