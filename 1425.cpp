#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int a[1000005];

int main(){
	int i , j , n , m ;
	while( scanf( "%d%d" , &n , &m ) != EOF ){
		for( i = 0 ; i < n ; ++i )
			scanf( "%d" , a+i );
		sort( a , a+n );
		printf( "%d" , a[n-1] );
		for( int i = 1 ; i < m ; ++i ){
			printf( " %d" , a[n-1-i] );
		}
		printf( "\n" );
	}
	return 0;
}