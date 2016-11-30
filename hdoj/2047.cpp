#include<cstdio>
__int64 a[41];
int main()
{
    a[0]=3;
    a[1]=8;
    for(int i=2;i<41;i++)
        a[i]=2*(a[i-1]+a[i-2]);
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",a[n-1]);
    return 0;
}