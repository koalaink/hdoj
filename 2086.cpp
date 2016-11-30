#include<iostream>
using namespace std;
int main()
{
int n,i,j;
double min,max,abc[3001],sum ;//公式A1=(n*min+max-2（n*c1+(n-1)*c2+....+cn）)/(n+1)
while(cin>>n)
{
    sum=0;
cin>>min>>max;
for(i=1;i<=n;i++)
cin>>abc[i];
for(i=n,j=1;i>=1&&j<=n;i--,j++)
   sum+=i*abc[j];
printf("%.2lf\n",(n*min+max-2*sum)/(n+1));
}
return 0;
}