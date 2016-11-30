#include<algorithm>
#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<math.h>
using namespace std;

const int MAX = 205 ;

struct Node{
	int x , y ;
	double val ;
};

struct Node1{
	int x , y ;
};

Node1 island[MAX] ;
Node edge[MAX*(MAX-1)/2] ;
int father[MAX] ;
int son[MAX] ;
int n , num ;
double ans ;

bool cmp( const Node& a , const Node& b ){
	return a.val < b.val ;
}

void Init(){
	num = 0 ;
	for( int i = 0 ; i < n ; ++i ){
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

void Union( int x , int y , double w ){
	x = find(x) ;
	y = find(y) ;
	if( x != y ){
		++num ;
		ans += w ;
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
	int cas ;
	int x , y , m ;
	scanf( "%d" , &cas ) ;
	while( cas-- ){
		scanf( "%d" , &n ) ;
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%d%d" , &island[i].x , &island[i].y ) ;
		}
		m = n*(n-1)/2 ;
		int index = 0 ;
		for( int i = 0 ; i < n ; ++i ){
			int xx = island[i].x ;
			int yy = island[i].y ;
			for( int j = i+1 ; j < n ; ++j ){
				int xxx = island[j].x ;
				int yyy = island[j].y ;
				edge[index].x = i ;
				edge[index].y = j ;
				edge[index++].val = sqrt((double)(xx-xxx)*(xx-xxx)+(yy-yyy)*(yy-yyy)) ;
			}
		}
		Init() ;
		ans = 0 ;
		sort( edge , edge+m , cmp ) ;
		int i = 0 ;
		while( i < m && edge[i].val < 10 ) ++i ;
		for(  ; i < m && edge[i].val <= 1000 ; ++i ){
			Union( edge[i].x , edge[i].y , edge[i].val ) ;
			if( num == n-1 )
				break ;
		}
		if( num != n-1 )
			printf( "oh!\n" );
		else
			printf( "%.1lf\n" , ans*100 ) ;
	}
	return 0 ;
}