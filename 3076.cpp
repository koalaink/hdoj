/*
sample input:
5 5
1.000 0.000 0.000 0.000 0.000 0.000
0.000 0.000 0.000 0.000 0.000 1.000
5 5
0.000 0.000 0.000 0.000 0.000 1.000
1.000 0.000 0.000 0.000 0.000 0.000
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
#define MAX 2005
using namespace std;

double dp[MAX][MAX] ;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int hp1 , hp2 ;
	double pro[2][6] ;
	double pro_win , pro_same , pro_lose ;
	while( scanf( "%d%d" , &hp2 , &hp1 ) != EOF ){
		scanf( "%lf%lf%lf%lf%lf%lf" , &pro[0][0] , &pro[0][1] , &pro[0][2], &pro[0][3], &pro[0][4], &pro[0][5] );
		scanf( "%lf%lf%lf%lf%lf%lf" , &pro[1][0] , &pro[1][1] , &pro[1][2], &pro[1][3], &pro[1][4], &pro[1][5] );
		pro_win = pro_lose = 0 ;
		for( int i = 1 ; i < 6 ; ++i ){
			for( int j = 0 ; j < i ; ++j ){
				pro_win += pro[0][i]*pro[1][j] ;
				pro_lose += pro[1][i]*pro[0][j] ;
			}
		}
		pro_same = 1 - pro_win - pro_lose ;
		memset(dp,0,sizeof(dp)) ;
		dp[0][0] = 1 ;
		for( int i = 0 ; i <= hp2 ; ++i ){
			for( int j = 0 ; j <= hp1 ; ++j ){
				if( i < hp2 ) dp[i+1][j] += dp[i][j]*pro_win/(1-pro_same) ;
				if( j < hp1 ) dp[i][j+1] += dp[i][j]*pro_lose/(1-pro_same) ;
			}
		}
		double ans = 0 ;
		for( int i = 0 ; i < hp1 ; ++i )
			ans += dp[hp2-1][i]*pro_win/(1-pro_same) ;
		printf( "%.06lf\n" , ans ) ;
	}
	return 0 ;
}