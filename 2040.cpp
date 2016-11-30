#include<iostream>
using namespace std;
main()
{
    int n,a,b,sum,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        sum=0;
        for(i=1;i<a;i++)
            if(!(a%i))
                sum+=i;
        if(sum==b){
            sum=0;
            for(i=1;i<b;i++)
                if(!(b%i))
                    sum+=i;
        }
        if(sum==a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}