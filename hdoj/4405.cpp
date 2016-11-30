/*
sample input:
2 0
8 3
2 4
4 5
7 8
0 0
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<map>
#define MAXN 100005
#define MAXM 1005
using namespace std ;

int n , m ;
double dp[MAXN] ;
map<int,int> line ;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int f , t ;
	while( scanf( "%d%d" , &n , &m ) , n || m ){
		line.clear() ;
		for( int i = 0 ; i < m ; ++i ){
			scanf( "%d%d" , &f , &t ) ;
			line[f] = t ;
		}
		memset(dp,0,sizeof(dp)) ;
		for( int i = n-1 ; i >= 0 ; --i ){
			if( line[i] )
				dp[i] = dp[line[i]] ;
			else{
				for( int j = 1 ; j <= 6 ; ++j ){
					if( i+j > n ) break ;
					dp[i] += dp[i+j]*1.0/6 ;
				}
				dp[i] += 1 ;
			}
		}
		printf( "%.04lf\n" , dp[0] ) ;
	}
	return 0 ;
}