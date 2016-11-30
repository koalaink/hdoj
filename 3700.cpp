/*
sample example:
12 12
2
23:00-01:00
01:22-02:00
3 4
3
11:00-11:09
07:00-08:00
19:00-19:59
 */
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<stdio.h>
#define MAXN 25
using namespace std;

struct time{
	int f , t ;
	int l ;
};

bool mycmp(time a , time b ){
	return a.f<b.f ;
}

int A , B , n ;
time k[MAXN] ;
bool mark[MAXN] ;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int a , b , c , d ;
	while( scanf( "%d%d" , &A , &B ) != EOF ){
		scanf( "%d" , &n ) ;
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%d:%d-%d:%d" , &a , &b , &c , &d ) ;
			k[i].f = a*60+b ;
			k[i].t = c*60+d ;
			k[i].l = k[i].t-k[i].f+1 ;
			k[i].l += k[i].l>0?0:(24*60) ;
		}
		sort(k,k+n,mycmp) ;

		bool flag = true ;
		int i = 0 ;
		while( (k[(i%n)].f+24*60-k[(i+n-1)%n].t-1)%(24*60) < A*60 && i < n ) ++i ;
		if( i >= n ) flag = false ;

		int aw = 0 ;
		int ans = n ;
		memset(mark,true,sizeof(mark)) ;
		for( int j = 0 ; j < n ; ++i , ++j ){
			aw += k[i].l ;
			if( aw > B*60 ){
				// printf("...%d %d\n" , i , aw ) ;
				flag = false ;break ;
			}
			if( (k[((i+1)%n)].f+24*60-k[i%n].t-1)%(24*60) < A*60 ){
				aw += (k[((i+1)%n)].f+24*60-k[i%n].t-1)%(24*60) ;
				ans-- ;
				mark[i%n] = false ;
			}
			else
				aw = 0 ;
		}

		if( !flag ){
			printf( "No\n" ) ;
		}
		else{
			printf( "Yes\n%d\n" , ans ) ;
			for( int i = 0 ; i < n ; ++i ){
				if( !mark[i] ) continue ;
				k[i%n].t = (k[i%n].t+1)%(24*60) ;
				k[(i+1)%n].f =  (k[(i+1)%n].f+24*60-1)%(24*60);
				printf( "%02d:%02d-%02d:%02d\n" , k[i%n].t/60 , k[i%n].t%60 , k[(i+1)%n].f/60 , k[(i+1)%n].f%60 ) ;
			}
		}
	}
	return 0 ;
}