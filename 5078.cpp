/*
sample input:
2
5
2 1 9
3 7 2
5 9 0
6 6 3
7 6 0
10
11 35 67
23 2 29
29 58 22
30 67 69
36 56 93
62 42 11
67 73 29
68 19 21
72 37 84
82 24 98
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <cmath>
#define MAX 1005
using namespace std;

int n;
double point[2][3];

double dis(double x1,double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main(){
    // freopen("0input.txt","r",stdin);
    int t,i;
    double ans;
    int pre,cur;
    scanf("%d",&t);
    while(t--){
        ans=-1;
        cur=1;pre=0;
        scanf("%d",&n);
        if(n) scanf("%lf %lf %lf",&point[pre][0],&point[pre][1],&point[pre][2]);
        for(i=1;i<n;++i){
            scanf("%lf %lf %lf",&point[cur][0],&point[cur][1],&point[cur][2]);
            ans=max(ans,dis(point[cur][1],point[cur][2],point[pre][1],point[pre][2])/(point[cur][0]-point[pre][0]));
            swap(cur,pre);
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}