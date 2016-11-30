/*#include<iostream>
#include<stdio.h>
using namespace std;

const int INF = 10000;
const int MAX = 105;
int matrix[MAX][MAX];
bool visit[MAX];

int main(){
	int n , m , f , t , w ;
	while( scanf( "%d" , &n ) , n ){
		m = n*(n-1)/2 ;
		memset( matrix , INF , sizeof(matrix) );
		while( m-- ){
			scanf( "%d%d%d" , &f , &t , &w );
			matrix[f][t] = matrix[t][f] = w ;
		}
		int pre = 1 , ans = 0 , min;
		memset( visit , false , sizeof(visit) );
		visit[1] = true;
		for( int i = 1 ; i < n ; ++i ){
			int min = INF ;
			int index = 1;
			for( int j = 1 ; j <= n ; ++j ){
				if( visit[j] ) continue;
				int Min = INF;
				for( int k = 1 ; k <= n ; ++k ){
					if( !visit[k] ) continue;
					if( Min > matrix[j][k] ){
						Min = matrix[j][k];
					}
				}
				if( min > Min ){
					min = Min ;
					index = j ;
				}
			}
			visit[index] = true;
			ans += min;
		}
		printf( "%d\n" , ans );
	}
	return 0;
}*/

#include<iostream>
#include<stdio.h>
using namespace std;

const int INF = 0xffffff ;
const int MAX = 105 ;
int matrix[MAX][MAX];
bool visit[MAX];
int dist[MAX];
int n ;

int prim( int s = 1 ){
	int ans = 0 ;
	for( int i = 1 ; i <= n ; ++i ){
		dist[i] = matrix[s][i] ;
		visit[i] = false ;
	}
	visit[s] = true ;
	for( int i = 1 ; i < n ; ++i ){
		int min = INF ;
		int index = s ;
		for( int j = 1 ; j <= n ; ++j )
			if( !visit[j] && dist[j] < min )
				min = dist[j] , index = j ;
		visit[index] = true ;
		ans += dist[index] ;
		for( int j = 1 ; j <= n ; ++j )
			if( !visit[j] && dist[j] > matrix[index][j] )
				dist[j] = matrix[index][j] ;
	}
	return ans ;
}

int main(){
	int f , t , w ;
	while( scanf( "%d" , &n ) , n ){
		for( int i = 0 ; i < n*(n-1)/2 ; ++i ){
			scanf( "%d%d%d" , &f , &t , &w ) ;
			matrix[f][t] = matrix[t][f] = w ;
		}
		printf( "%d\n" , prim() );
	}
	return 0;
}