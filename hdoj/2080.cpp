#include<iostream>
#include<cmath>
#define PI 3.1415926
using namespace std;
int main(){
    double x1,x2,y1,y2,r;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        r=(x1*x2+y1*y2)/(sqrt((double)x1*x1+y1*y1)*sqrt((double)x2*x2+y2*y2));
        r=acos(r);
        r=(r>180?(360-r):r)*180.0/PI;
        printf("%.2lf\n",r);
    }
}