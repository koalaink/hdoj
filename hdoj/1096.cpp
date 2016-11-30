#include<iostream>
using namespace std;
main()
{
    int n,m,temp,sum;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        sum=0;
        while(m--){
            scanf("%d",&temp);
            sum+=temp;
        }
        printf("%d\n",sum);
        if(n) printf("\n");
    }
}