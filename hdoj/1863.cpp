#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
	int x , y , val ;
};

const int MAX_V = 105 ;
const int MAX_E = MAX_V*(MAX_V-1)/2 ;
Node edge[MAX_E] ;
int father[MAX_V] ;
int son[MAX_V] ;
int n , m ;
int block , ans ;

bool cmp( const Node& a , const Node& b ){
	return a.val < b.val ;
}

void Init(){
	block = m ;
	ans = 0 ;
	for( int i = 1 ; i <= m ; ++i ){
		father[i] = i ;
		son[i] = 1 ;
	}
	return ;
}

int find( int x ){
	if( x != father[x] )
		father[x] = find(father[x]) ;
	return father[x] ;
}

void Union( Node e ){
	int x = find(e.x) ;
	int y = find(e.y) ;
	if( x != y ){
		--block ;
		ans += e.val ;
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
	while( scanf( "%d%d" , &n , &m ) , n ){
		for( int i = 0 ; i < n ; ++i )
			scanf( "%d%d%d" , &edge[i].x , &edge[i].y , &edge[i].val ) ;
		sort( edge , edge+n , cmp );
		Init() ;
		for( int i = 0 ; i < n ; ++i ){
			Union(edge[i]) ;
			if( block == 1 )
				break ;
		}
		if( block == 1 )
			printf( "%d\n" , ans ) ;
		else
			printf( "?\n" );
	}
	return 0 ;
}