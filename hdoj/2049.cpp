#include <stdio.h>
__int64 fac(int a)//阶乘
{
    if(a==0)
        return 1;
    else
        return a*fac(a-1);
}
__int64 C(int n,int m)//组合
{
    return fac(n)/(fac(m)*fac(n-m));
}
int main()
{
    __int64 p[30]={1,0,1};
    int t,i,n,m;                    
    scanf("%d",&t);
    i=3;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(;i<=m;i++)
            p[i]=(i-1)*(p[i-1]+p[i-2]);
        printf("%I64d\n",C(n,m)*p[m]);
    }
    return 0;
}