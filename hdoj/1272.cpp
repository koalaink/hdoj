#include<iostream>
#include<stdio.h>
using namespace std ;

#define MAX 100005

struct Node{
	int x , y ;
};

int father[MAX] ;
Node edge[MAX] ;
bool has[MAX] ;
int son[MAX] ;
int n , m , cnt ;

void mymax( int a , int b , int& c ){
	if( a > b && a > c ){
		c = a ;
		return ;
	}
	if( b > a && b > c ){
		c = b ;
		return ;
	}
	return ;
}

void Init( int& root ){
	n = m = root = 0 ;
	for( int i = 1 ; i < MAX ; ++i ){
		has[i] = false ;
		father[i] = i ;
		son[i] = 1 ;
	}
	return ;
}

int find( int p ){
	if( p != father[p] )
		father[p] = find(father[p]) ;
	return father[p] ;
}

void Union( int x , int y ){
	++m ;
	x = find(x) ;
	y = find(y) ;
	if( x !=  y ){
		if( son[x] >= son[y] ){
			father[y] = x ;
			son[x] += son[y] ;
		}
		else{
			father[x] = y ;
			son[y] += son[x] ;
		}
	}
	return ;
}

int main(){
	int tmp ;
	int root ;
	int a , b , i ;
	while( scanf( "%d%d" , &a , &b ) ){
		if( a == -1 && b == -1 )
			break ;
		if( a == 0 && b == 0 ){
			printf( "Yes\n" ) ;
			continue ;
		}
		Init(root) ;
		Union(a,b) ;
		has[a] = has[b] = true ;
		while( scanf( "%d%d" , &a , &b ) , a || b ){
			Union(a,b) ;
			has[a] = has[b] = true ;
		}
		for( int i = 1 ; i < MAX ; ++i ){
			if( !has[i] ) continue ;
			++n ;
			if( find(i) == i ){
				root++ ;
			}
			if( root > 1 )
				break ;
		}
		if( root > 1 )
			printf( "No\n" ) ;
		else if( n != m+1 )
			printf( "No\n" ) ;
		else
			printf( "Yes\n" );
	}
	return 0 ;
}