#include<iostream>
#include<stdio.h>
using namespace std;

int f[3000001];

int main(){
    int n,t;
    int val[35],index;
    double all;
    while(scanf("%lf%d",&all,&n),n){
        all=(int)(all*100);
        index=0;
        for(int i=0;i<n;i++){
            int A,B,C,flag;
            double tmp;
            char type;
            A=B=C=flag=0;
            scanf("%d",&t);
            for(int j=0;j<t;j++){
                scanf(" %c:%lf",&type,&tmp);
                if(type=='A') A+=(int)(tmp*100);
                else if(type=='B') B+=(int)(tmp*100);
                else if(type=='C') C+=(int)(tmp*100);
                else flag=1;
            }
            if(A+B+C>100000||A>60000||B>60000||C>60000) flag=1;
            if(!flag) val[index++]=A+B+C;
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<index;i++){
            for(int j=all;j>=val[i];j--){
                f[j]=(f[j]>(f[j-val[i]]+val[i]))?f[j]:(f[j-val[i]]+val[i]);
            }
        }
        printf("%.2lf\n",(double)f[(int)all]/100);
    }
}