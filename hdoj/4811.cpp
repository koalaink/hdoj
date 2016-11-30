/*
sample input:
2 2 2
3 3 3
4 4 4
0 0 4
 */
#include<iostream>
#include<stdio.h>
#define LL long long
using namespace std;

int main(){
	// freopen("0input.txt","r",stdin) ;
	LL a , b , c , sum , n , ans ;
	while( scanf( "%I64d%I64d%I64d" , &a , &b , &c ) != EOF ){
		ans = 0 ;
		sum = a + b + c ;
		n = (a>1?2:a) + (b>1?2:b) + (c>1?2:c) ;
		for( int i = 0 ; i < n ; ++i )
			ans += i ;
		ans += (sum-n)*n ;
		printf( "%I64d\n" , ans ) ;
	}
	return 0 ;
}