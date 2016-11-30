#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double dis[210];
    int n;
    int x1,y1,x2,y2;
    dis[0]=0;dis[1]=1;
    for(int i=2;i<210;i++)
        dis[i]=dis[i-1]+sqrt((double)i*i+(i-1)*(i-1))+sqrt((double)2)*(i-1);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        double dis1,dis2,ans;
        dis1=dis[x1+y1]+sqrt((double)2)*x1;
        dis2=dis[x2+y2]+sqrt((double)2)*x2;
        (dis1>dis2)?(ans=dis1-dis2):(ans=dis2-dis1);
        printf("%.3lf\n",ans);
    }
}