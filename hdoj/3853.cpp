/*
sample input:
2 2
0.00 0.50 0.50    0.50 0.00 0.50
0.50 0.50 0.00    1.00 0.00 0.00
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
#define MAX 1005
using namespace std;

int r , c ;
double map[MAX][MAX][3] ;
int dir[3][2] = {0,0,0,1,1,0} ;
double dp[MAX][MAX] ;

int main(){
	// freopen("0input.txt","r",stdin) ;
	while( scanf( "%d%d" , &r , &c ) != EOF ){
		for( int i = 1 ; i <= r ; ++i ){
			for( int j = 1 ; j <= c ; ++j ){
				scanf( "%lf%lf%lf" , &map[i][j][0] , &map[i][j][1] , &map[i][j][2] ) ;
			}
		}
		memset(dp,0,sizeof(dp)) ;
		for( int i = r ; i >= 1 ; --i ){
			for( int j = c ; j >= 1 ; --j ){
				if( i == r && j == c ) continue ;
				double tmp = 2*(map[i][j][0]) ;
				if( i + 1 <= r )
					tmp += (dp[i+1][j]+2)*map[i][j][2] ;
				if( j + 1 <= c )
					tmp += (dp[i][j+1]+2)*map[i][j][1] ;
				if( map[i][j][0] == 1 )
					dp[i][j] = 0 ;
				else
					dp[i][j] = tmp/(1-map[i][j][0]) ;
			}
		}

		printf( "%.03lf\n" , dp[1][1] ) ;
	}
	return 0 ;
}