#include<stdio.h>
#include<math.h>
int main()
{
    int m,n;
    int i,j;
    while(scanf("%d %d",&n,&m)!=EOF&&m||n)
    {
        for(j=sqrt((double)2*m);j>=1;j--)
        {
            i=(2*m/j+1-j)/2;
            if((i+i+j-1)*j==2*m)
                printf("[%d,%d]\n",i,i+j-1);
        }
        printf("\n");
    }
}