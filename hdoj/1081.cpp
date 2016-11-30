#include<iostream>
#include<stdio.h>
using namespace std;

int a[105][105] , c[105][105][105];
int dp[105][105][105];

int max(const int& a , const int& b){
    return a>b?a:b;
}

int main(){
    int n , i , j , k , l ;
    int MAX;
    while( scanf( "%d" , &n ) != EOF ){
        for( i = 0 ; i < n ; ++i )
            for( j = 0 ; j < n ; ++j )
                scanf( "%d" , &a[i][j] );
        memset( c , 0 , sizeof(c) );
        memset( dp , 0 , sizeof(dp) );
        MAX = -99999999;
        for( i = 0 ; i < n ; ++i ){
            for( j = i ; j < n ; ++j ){
                for( k = 0 ; k < n ; ++k ){
                    for( l = i ; l <= j ; ++l ) c[i][j][k] += a[l][k] ;
                    dp[i][j][k] = max(dp[i][j][k-1]+c[i][j][k],c[i][j][k]);
                    if( dp[i][j][k] > MAX ) MAX = dp[i][j][k];
                }
            }
        }
        printf( "%d\n" , MAX );
    }
    return 0;
}