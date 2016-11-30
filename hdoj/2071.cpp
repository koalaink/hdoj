#include<iostream>
using namespace std;
int main(){
    int t,n;
    double temp,max;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%lf",&max);
        while(--n){
            scanf("%lf",&temp);
            if(temp>max) max=temp;
        }
        printf("%.2lf\n",max);
    }
    return 0;
}