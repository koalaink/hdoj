#include<iostream>
#include<stdio.h>
using namespace std;

int dp[100001][11];

int max( const int& a , const int& b , const int& c ){
    int tmp = a > b ? (a > c ? a : c ) : ( b > c ? b : c ) ;
    return tmp;
}

int main(){
    int n , i , j , x , t , mt ;
    while( scanf( "%d" , &n ) , n ){
        memset( dp , 0 , sizeof(dp) );
        mt = 0 ;
        while( n-- ){
            scanf( "%d%d" , &x , &t );
            mt = t > mt ? t : mt ;
            dp[t][x] += 1 ;
        }
        for( i = mt - 1 ; i >= 0 ; --i ){
            for( j = 0 ; j <= 10 ; ++j ){
                dp[i][j] += max( (j ? dp[i+1][j-1] : 0) , dp[i+1][j] , (j==10 ? 0 : dp[i+1][j+1]) );
            }
        }
        printf( "%d\n" , dp[0][5] );
    }
    return 0;
}