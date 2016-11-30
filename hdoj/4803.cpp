/*
sample input:
1 1
3 8
9 31
4 4
1 8
 */

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int n , m ;
	while( scanf( "%d%d" , &n , &m ) != EOF ){
		if( !n || !m || n > m ){
			printf( "-1\n" ) ;
			continue ;
		}
		int ans ;
		double x , y , p ;
		x = 1 ;
		y = p = (int)(m/n) ;
		ans = y - 1 ;
		while( x < n ){
			x++ ; y = x * p ; ans++ ;
			// printf( "%lf %lf %lf %d\n" , x , y , p , ans );
			while( (y+1)/x*n < m+1 ){
				y++ ; p = y/x ; ans++ ;
			}
		}
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}