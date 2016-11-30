#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

const int INF = 0xffffff ;
const int MAX = 105 ;
int matrix[MAX][MAX] ;
bool visit[MAX] ;
int cost[MAX] ;
int n ;

int Prim( int s = 1 ){
	int i , j ;
	int ans = 0 ;
	for( i = 1 ; i <= n ; ++i ){
		cost[i] = matrix[s][i] ;
		visit[i] = false ;
	}
	visit[s] = true ;
	for( i = 1 ; i < n ; ++i ){
		int min = INF ;
		int index = s ;
		for( j = 1 ; j <= n ; ++j )
			if( !visit[j] && cost[j] < min )
				min = cost[j] , index = j ;
		visit[index] = true ;
		ans += min ;
		for( j = 1 ; j <= n ; ++j )
			if( !visit[j] && matrix[index][j] < cost[j] )
				cost[j] = matrix[index][j] ;
	}
	return ans ;
}

int main(){
	int f , t , w , flag ;
	while( scanf( "%d" , &n ) , n ){
		for( int i = 0 ; i < n*(n-1)/2 ; ++i ){
			scanf( "%d%d%d%d" , &f , &t , &w , &flag ) ;
			if( flag )
				matrix[f][t] = matrix[t][f] = 0 ;
			else
				matrix[f][t] = matrix[t][f] = w ;
		}
		printf( "%d\n" , Prim() ) ;
	}
	return 0;
}