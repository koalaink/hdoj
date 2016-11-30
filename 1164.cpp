#include<iostream>
const int MAX=65536;
int prime[MAX]={0};
void getprime(){
    prime[0]=prime[1]=1;
    for(int i=2;i<257;i++)
        for(int j=i*i;j<MAX;j+=i)
            prime[j]=1;
}

int main(){
    getprime();
    int i,x;
    while(scanf("%d",&x)==1){
        for(i=2;i<=x;i++){
            if(!prime[x]){ printf("%d",x);break;}
            if(prime[i]) continue;
            if(x%i==0){
                while(x%i==0){
                    printf("%d",i);
                    x/=i;
                    if(x!=1) printf("*");
                }
            }
        }
        printf("\n");
    }
}