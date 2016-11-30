#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int c , n , m , i , j , r , tmpm , k[25][1001] , dp[25][1001] ;
    scanf( "%d" , &c );
    while( c-- ){
        scanf( "%d%d" , &n , &m );
        for( i = 1 ; i <= n ; ++i )
            for ( j = 1 ; j <= m ; ++j )
                scanf( "%d" , &k[i][j] );
        memset( dp , 0 , sizeof(dp) );
        for( i = 1 ; i <= n ; ++i ){
            for( j = 1 ; j <= m ; ++j ){
                if( i == 1 && j==1 ) tmpm = 0;
                else if( i == 1 ) tmpm = dp[i][j-1];
                else if ( j == 1 ) tmpm = dp[i-1][j];
                else tmpm = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j] ;
                for( r = 1 ; r < j ; ++r )
                    if( j % r == 0 && tmpm < dp[i][r] )
                        tmpm = dp[i][r];
                dp[i][j] = tmpm + k[i][j] ;
            }
        }
        printf( "%d\n" , dp[n][m] );
    }
}