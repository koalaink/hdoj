/*
sample input:
18
111
1111
 */
#include <iostream>
#include <stdio.h>
using namespace std;

long long k,kk;
int r;

long long mpower(long long k,int ind,long long n){
	long long res=1;
	for(int i=1;i<=ind;++i){
		res*=k;
		if( res>n || res<0 ) return 0;
	}
	return res;
}

long long fun(long long le,long long ri,long long n){
	// if( r==11) printf("%I64d %I64d\n",le,ri);
	if(ri<le) return 0;
	long long mid=(ri+le)/2;
	long long tmp=0,p=1;
	int i;
	for(i=1;i<=r;++i){
		/////////////////////////////////////////////////
		// if( p>n|| p>n/mid || tmp>n-p*mid ) break; //
		/////////////////////////////////////////////////
		if( p>n || p>n/mid || tmp>n || tmp>n-p*mid ) break;
		p*=mid;
		tmp+=p;
		// if( n/p < mid ) break;
	}
	// if( r==2)printf("%I64d\n",tmp);
	// printf("%lf\n",tmp);
	if( tmp == n )
		return mid;
	else if( tmp>n || i<=r )
		return fun(le,mid-1,n);
	return fun(mid+1,ri,n);
}

int main(){
	// freopen("0input.txt","r",stdin);
	long long n ;
	while(scanf("%I64d",&n)!=EOF){
		int ansr=1 ;
		long long ansk=n-1 ;
		for(r=2;r<50;++r){
			k = fun(2,n,n);
			kk =fun(2,n-1,n-1);
			k=(k<kk?(k>0?k:kk):(kk>0?kk:k));
			// printf("%I64d\n",k);
			if( k>0 ){
				// printf("%d %I64d\n",r,k);
				if( r*k>0 && r*k < ansr*ansk ){
					ansr=r;ansk=k;
				}
			}
		}
		// if( ansr!=1)	
		printf( "%d %I64d\n",ansr,ansk);
	}
	return 0 ;
}