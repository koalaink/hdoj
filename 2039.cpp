#include<iostream>
int main(){
    int n;
    double a,b,c,temp;
    scanf("%d",&n);
    while(n--){
        scanf("%lf%lf%lf",&a,&b,&c);
        if(a>c) (temp=a,a=c,c=temp);
        if(b>c) (temp=b,b=c,c=temp);
        if(a+b>c && a-b<c && b-c<c ) printf("YES\n");
        else printf("NO\n");
    }
}