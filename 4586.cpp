/*
sample input:
6 1 2 3 4 5 6
0
4 0 0 0 0
1 3
 */
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int n , m , tmp ;
	double sum ;
	while( scanf( "%d" , &n ) != EOF ){
		sum = 0 ;
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%d" , &tmp ) ;
			sum += tmp ;
		}
		scanf( "%d" , &m ) ;
		for( int i = 0 ; i < m ; ++i )
			scanf( "%d" , &tmp ) ;
		if( m >= n && sum > 0 )
			printf( "inf\n" ) ;
		else if( m >= n )
			printf( "0.00\n" ) ;
		else
			printf( "%.02lf\n" , sum/(n-m) ) ;
	}
	return 0 ;
}