/*
sample input:
2

5
1
2
3
4
5

5
5
4
3
2
2
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
#define MAX 105
#define INF 1000000
using namespace std;

int dp[MAX][MAX] ;
int arr[MAX] ;
int sum[MAX] ;
int n ;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int t , cas ;
	while( scanf( "%d" , &t ) != EOF ){
		cas = 1 ;
		while( t-- ){
			scanf( "%d" , &n ) ;
			for( int i = 1 ; i <= n ; ++i )
				scanf( "%d" , arr+i ) ;
			memset(dp,0,sizeof(dp)) ;

			sum[0] = 0 ;
			for( int i = 1 ; i <= n ; ++i )
				sum[i] = sum[i-1] + arr[i] ;

			for( int i = 1 ; i <= n ; ++i )
				for( int j = i+1 ; j <= n ; ++j )
					dp[i][j] = INF ;

			for( int i = n ; i >= 1 ; --i ){
				for( int j = i+1 ; j <= n ; ++j ){
					for( int k = i ; k <= j ; ++k ){
						dp[i][j] = min(dp[i][j],dp[i+1][k]+dp[k+1][j]+arr[i]*(k-i)+(k-i+1)*(sum[j]-sum[k])) ;
					}
				}
			}

			printf( "Case #%d: %d\n" , cas++ , dp[1][n] ) ;
		}
	}
	return 0 ;
}