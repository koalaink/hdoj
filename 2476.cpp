/*
sample input:
zzzzzfzzzzz
abcdefedcba
abababababab
cdcdcdcdcdcd
 */
#include<iostream>
#include<memory.h>
#include<string.h>
#include<stdio.h>
#define MAX 105
using namespace std;

int dp[MAX][MAX] ;
char a[MAX] , b[MAX] ;
int ans[MAX] ;
int n ;

int min( int x , int y ){
	return x <= y ? x : y ;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	while( scanf( "%s" , a+1 ) != EOF ){

		scanf( "%s" , b+1 ) ;
		n = strlen(a+1) ;

		memset(dp,0,sizeof(dp)) ;
		memset(ans,0,sizeof(ans)) ;
		for( int i = 1 ; i <= n ; ++i )
			dp[i][i] = 1 ;

		for( int i = n-1 ; i >= 1 ; --i ){
			for( int j = i+1 ; j <= n ; ++j ){
				dp[i][j] = dp[i+1][j] + 1 ;
				for( int k = i+1 ; k <= j ; ++k ){
					if( b[i] == b[k] )
						dp[i][j] = min(dp[i][j],dp[i+1][k-1]+dp[k][j]) ;
				}
			}
		}

		for( int i = 1 ; i <= n ; ++i ){
			ans[i] = dp[1][i] ;
			
			if( a[i] == b[i] ){
				if( i == 1 )
					ans[i] = 0 ;
				else
					ans[i] = ans[i-1] ;
			}
			else{
				for( int j = 1 ; j < i ; ++j ){
					ans[i] = min(ans[i],ans[j]+dp[j+1][i]) ;
				}
			}
		}

		printf( "%d\n" , ans[n] ) ;
	}
	return 0 ;
}