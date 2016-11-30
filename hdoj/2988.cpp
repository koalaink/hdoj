#include<algorithm>
#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

const int INF = 0xffffff ;
const int MAX = 200005 ;

struct node{
	int x , y ;
	int w ;
};

int father[MAX] ;
int son[MAX] ;
int ans , esum ;
int m , n ;
node edge[MAX] ;

bool cmp( const node& a , const node& b ){
	return a.w < b.w ;
}

void init(){
	for( int i = 0 ; i < m ; ++i ){
		father[i] = i ;
		son[i] = 1 ;
	}
	ans = 0 ;
	esum = 0 ;
	return ;
}

int find_fat( int x ){
	if( father[x] != x )
		father[x] = find_fat(father[x]) ;
	return father[x] ;
}

bool Union( int x , int y ){
	x = find_fat(x) ;
	y = find_fat(y) ;
	if( x == y )
		return false;
	if( son[x] > son[y] ){
		father[y] = x ;
		son[x] += son[y] ;
	}
	else{
		father[x] = y ;
		son[y] += son[x] ;
	}
	return true;
}

void Kruskal(){
	for( int i = 0 ; i < n ; ++i ){
		if( Union(edge[i].x,edge[i].y) ){
			ans += edge[i].w ;
			++esum ;
		}
		if( esum == m-1 ){
			break ;
		}
	}
	return ;
}

int main(){
	int sum ;
	while( scanf( "%d%d" , &m , &n ) , m || n ){
		init() ;
		sum = 0 ;
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%d%d%d" , &edge[i].x , &edge[i].y , &edge[i].w ) ;
			sum += edge[i].w ;
		}
		sort( edge , edge+n , cmp ) ;
		Kruskal() ;
		printf( "%d\n" , sum - ans ) ;
	}
	return 0;
}