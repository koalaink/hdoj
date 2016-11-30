#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n , i , j , tmp , tmpm , a[1001] , dp[1001] ;
    bool used[1001];
    while( scanf( "%d" , &n ) , n ){
        for( i = 0 ; i < n ; ++i )
            scanf( "%d" , a + i ) ;
        memset( dp , 0 , sizeof(dp) );
        memset( used , false , sizeof(used) );
        dp[0] = a[0] ;
        for( i = 1 ; i < n ; ++i ){
            tmpm = tmp = 0 ;
            for( j = 0 ; j <= i ; ++j ){
                if( a[j] < a[i] && dp[j] > tmpm) tmpm = dp[j];
            }
            dp[i] = tmpm + a[i] ;
        }
        tmpm = 0 ;
        for( i = 0 ; i < n ; ++i )
            if( dp[i] > tmpm ) tmpm = dp[i] ;
        printf( "%d\n" , tmpm );
    }
}