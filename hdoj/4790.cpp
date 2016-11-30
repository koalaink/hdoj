/*
sample input:
4
0 5 0 5 3 0
0 999999 0 999999 1000000 0
0 3 0 3 8 7
3 3 4 4 7 0
 */
#include <iostream>
#include <stdio.h>
using namespace std;
long long gcd(long long a,long long b){
	if( b==0 )
		return a;
	gcd(b,a%b);
}

long long getSt(long long a,long long p,long long m){
	return a+(m+p-a%p)%p;
}

long long getSum(long long a,long long b,long long p,long long m){
	long long st=getSt(a,p,m);
	// printf("%I64d %I64d %I64d\n",a,b,st);
	if( st>b ) return 0;
	long long n = (b-st)/p;
	if( n<0 ) return a;
	return (n+1)*n*p/2+(st-a+1)*(n+1);
}

int main(){
	long long a,b,c,d,p,m,e,f;
	long long st;
	long long ans;
	int t,cas=1;
	// freopen("0input.txt","r",stdin);
	scanf("%d",&t);
	while( t-- ){
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&p,&m);
		e = a+c;
		f = b+d;
		long long st=getSt(e,p,m);
		ans=getSum(e,f,p,m);
		ans-=getSum(a+d+1,f,p,m);
		// printf("%I64d\n",ans);
		ans-=getSum(b+c+1,f,p,m);
		/*while( st<=f ){
			ans+=st-e+1;
			if( a+d<st )
				ans-=st-a-d;
			if( b+c<st)
				ans-=st-b-c;
			st+=p;
		}*/
		// printf("%I64d\n",ans);
		long long sum = (b-a+1)*(d-c+1);
		long long g = gcd(ans,sum);
		printf( "Case #%d: %I64d/%I64d\n" , cas++ , ans/g,sum/g);
	}
	return 0;
}