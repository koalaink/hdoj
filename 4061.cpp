/*
sample input:
2
1
5
2
1 2
 */
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int t , cas ;
	int a1 , n , m ;
	while( scanf( "%d" , &t ) != EOF ){
		cas = 1 ;
		while( t-- ){
			n = 0 ;
			scanf( "%d" , &m ) ;
			int tmp ;
			for( int i = 1 ; i <= m ; ++i ){
				scanf( "%d" , &tmp ) ;
				if( i == 1 ) a1 = tmp ;
				n += tmp ;
			}
			printf( "Case %d: %.06lf\n" , cas++ , 1.0*a1/n ) ;
		}
	}
}