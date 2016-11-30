#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 10000005
int father[MAX] ;
int son[MAX] ;
int m ;
int ans ;

void mymax( int& a , int b ){
	if( b > a )
		a = b ;
	return ;
}

void Init(){
	ans = -1 ;
	for( int i = 1 ; i < MAX ; ++i ){
		father[i] = i ;
		son[i] = 1 ;
	}
}

int find( int x ){
	if( x != father[x] )
		father[x] = find(father[x]) ;
	return father[x] ;
}

void Union( int x , int y ){
	x = find(x) ;
	y = find(y) ;
	if( x != y ){
		if( son[x] >= son[y] ){
			father[y] = x ;
			son[x] += son[y] ;
		}
		else{
			father[x] = y ;
			son[y] += son[x] ;
		}
	}
}

int main(){
	// freopen( "0input.txt" , "r" , stdin ) ;
	int a , b ;
	while( scanf( "%d" , &m ) != EOF ){
		Init() ;
		while( m-- ){
			scanf( "%d%d" , &a , &b ) ;
			Union(a,b) ;
		}
		for( int i = 1 ; i < MAX ; ++i )
			mymax(ans,son[i]) ;
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}