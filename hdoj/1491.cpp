#include<iostream>
using namespace std;
int main(){
    int days[10]={0,31,28,31,30,31,30,31,31,30};
    int mon,day,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&mon,&day);
        if(mon>10 || mon==10 && day>21 ) printf("What a pity, it has passed!\n");
        else if(mon==10 && day==21 ) printf("It's today!!\n");
        else if(mon==10) printf("%d\n",21-day);
        else{
            int d=days[mon]-day+21;
            for(int i=mon+1;i<10;i++) d+=days[i];
            printf("%d\n",d);
        }
    }
}