#include<iostream>
using namespace std;
int main(){
    double t,n,c,s,cs,ss;
    scanf("%lf",&t);
    bool blank=false;
    while(t--){
        scanf("%lf",&n);
        bool flag=false;
        cs=0;ss=0;
        while(n--){
            char temp[55];
            scanf("%s%lf%lf",temp,&c,&s);
            if(s<60){
                flag=true;
            }else{
                cs+=c;
                ss+=c*s;
            }
        }
        if(blank) printf("\n");
        blank=true;
        if(flag) printf("Sorry!\n");
        else printf("%.2lf\n",ss/cs);
    }
}