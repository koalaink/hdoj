#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX = 1005 ;
int father[MAX] ;
int ans ;

void init( int n ){
	for( int i = 1 ; i <= n ; ++i )
		father[i] = i ;
	ans = n ;
	return ;
}

int find_fa( int x ){
	if( x != father[x] )
		father[x] = find_fa(father[x]) ;
	return father[x] ;
}

void Union( int x , int y ){
	int p = find_fa(x) ;
	int q = find_fa(y) ;
	if( p == q )
		return ;
	father[p] = q ;
	--ans ;
	return ;
}

int main(){
	int n , m , f , t ;
	while( scanf( "%d" , &n ) , n ){
		init(n) ;
		scanf( "%d" , &m ) ;
		for( int i = 0 ; i < m ; ++i ){
			scanf( "%d%d" , &f , &t ) ;
			Union( f , t ) ;
		}
		printf( "%d\n" , ans - 1 );
	}
	return 0;
}