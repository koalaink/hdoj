#include<stdio.h>
#include<string.h>
#include<math.h>
int prime[1000000] = {0};
int main(){
    int T,i,j,n,num,max,k;
    char name[100],s[100];
    prime[0]=prime[1]=1;
    for(i = 2; i <1000; i++)
        for(j = i * i; j <1000000; j+= i)
            prime[j] = 1;
    scanf("%d",&T);
    while(T--){
        max=-1;
        scanf("%d",&n);
        while(n--){
            k=0;
            scanf("%s%d",name,&num);
            for(i=2;i<=num;++i){
                if(prime[i])
                continue;
                if(num%i==0){
                    ++k;
                    num/=i;
                }
            }
            if(max<k){
                max=k;
                strcpy(s,name);
            }
            else if(max&&max==k){
                if(strcmp(s,name)>0)
                    strcpy(s,name);
            }
        }
        printf("%s\n",s);
    }
    return 0;
}