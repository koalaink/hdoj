#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int dp[35] = { 0 , 1 , 3 } ;
	for( int i = 3 ; i < 35 ; ++i )
		dp[i] = dp[i-1] + dp[i-2]*2 ;
	int t , n ;
	while( scanf( "%d" , &t ) != EOF ){
		while( t-- ){
			scanf( "%d" , &n ) ;
			printf( "%d\n" , dp[n] ) ;
		}
	}
	return 0 ;
}