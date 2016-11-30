#include<cstdio>
double count[51];
int main(){
    count[1] = 3;
    count[2] = 6;
    count[3] = 6;
    for(int i=4; i<51; i++)
        count[i] = 2*count[i-2]+count[i-1];
    int n;
    while(scanf("%d",&n)==1)
        printf("%0.lf\n", count[n]);
    return 0;
}
