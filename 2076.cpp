#include<iostream>
using namespace std;
int main(){
    int t;
    double h,m,s,ansh,ansm,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf",&h,&m,&s);
        if(h>=12) h-=12;
        ansh=(h+m/60+s/3600)/12*360;
        ansm=(m+s/60)/60*360;
        if(ansh>ansm) ans=ansh-ansm;
        else ans=ansm-ansh;
        if(ans>180) ans=360-ans;
        printf("%d\n",(int)ans);
    }
}