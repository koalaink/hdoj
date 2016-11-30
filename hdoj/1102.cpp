#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

const int INF = 0xffffff ;
const int MAX = 105 ;
int matrix[MAX][MAX] ;
bool visit[MAX] ;
int dist[MAX] ;
int n , m ;

int Prim( int s = 1 ){
	int i , j ;
	int ans = 0 ;
	for( i = 1 ; i <= n ; ++i ){
		dist[i] = matrix[s][i] ;
		visit[i] = false ;
	}
	visit[s] = true ;
	for( i = 1 ; i < n ; ++i ){
		int min = INF ;
		int index = s ;
		for( j = 1 ; j <= n ; ++j )
			if( !visit[j] && dist[j] < min )
				min = dist[j] , index = j ;
		visit[index] = true ;
		ans += min ;
		for( j = 1 ; j <= n ; ++j )
			if( !visit[j] && dist[j] > matrix[index][j] )
				dist[j] = matrix[index][j] ;
	}
	return ans;
}

int main(){
	int f , t ;
	while( scanf( "%d" , &n ) != EOF ){
		for( int i = 1 ; i <= n ; ++i )
			for( int j = 1 ; j <= n ; ++j )
				scanf( "%d" , &matrix[i][j] ) ;
		scanf( "%d" , &m ) ;
		for( int i = 0 ; i < m ; ++i ){
			scanf( "%d%d" , &f , &t ) ;
			matrix[f][t] = matrix[t][f] = 0 ;
		}
		printf( "%d\n" , Prim() );
	}
	return 0;
}