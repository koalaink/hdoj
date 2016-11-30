#include<algorithm>
#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

const int MAX_V = 505 ;
const int MAX_E = 25005 ;

struct Node{
	int x , y ;
	int val ;
};

Node edge[MAX_E] ;
int father[MAX_V] ;
int son[MAX_V] ;
int n , m , k ;
int block , ans , cnt ;

bool cmp( const Node& a , const Node& b ){
	return a.val < b.val ;
}

void Init(){
	block = n ;
	for( int i = 1 ; i <= n ; ++i ){
		father[i] = i ;
		son[i] = 1 ;
	}
	return ;
}

int Find_father( int p ){
	if( p != father[p] )
		father[p] = Find_father(father[p]) ;
	return father[p] ;
}

void Union( int p , int q ){
	p = Find_father(p) ;
	q = Find_father(q) ;
	if( p != q ){
		--block ;
		if( son[p] >= son[q] ){
			father[q] = p ;
			son[p] += son[q] ;
		}
		else{
			father[p] = q ;
			son[q] += son[p] ;
		}
	}
	return ;
}

void Union( Node e ){
	int p , q ;
	p = Find_father(e.x) ;
	q = Find_father(e.y) ;
	if( p != q ){
		ans += e.val ;
		++cnt ;
		if( son[p] >= son[q] ){
			father[q] = p ;
			son[p] += son[q] ;
		}
		else{
			father[p] = q ;
			son[q] += son[p] ;
		}
	}
	return ;
}

int main(){
	// freopen( "0input.txt" , "r" , stdin ) ;
	int f , t , w ;
	int cas ;
	scanf( "%d" , &cas ) ;
	while( cas-- ){
		scanf( "%d%d%d" , &n , &m , &k ) ;
		for( int i = 0 ; i < m ; ++i )
			scanf( "%d%d%d" , &edge[i].x , &edge[i].y , &edge[i].val ) ;
		sort( edge , edge+m , cmp ) ;
		Init() ;
		while( k-- ){
			scanf( "%d%d" , &w , &f );
			while( --w ){
				scanf( "%d" , &t );
				Union(f,t) ;
			}
		}
		if( block == 1 ){
			printf( "0\n" ) ;
			continue ;
		}
		ans = cnt = 0 ;
		for( int i = 0 ; i < m ; ++i ){
			Union(edge[i]) ;
			if( cnt == (block-1) )
				break ;
		}
		if( cnt < (block-1) )
			ans = -1 ;
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}