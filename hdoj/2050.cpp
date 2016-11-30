#include<stdio.h>
#define M(n) ((2)*(n)*(n)-(n)+(1))
int main()
{
    int c,m;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&m);
        printf("%d\n",M(m));
    }
    return 0;
}