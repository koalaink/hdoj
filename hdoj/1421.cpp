#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

    
int weight[2005];
int dp[2005][1005];

int min(const int& a , const int& b){
    return a<b?a:b;
}

int main(){
    int n , k , i , j ;
    while( scanf( "%d%d" , &n , &k ) != EOF ){
        for( i = 1 ; i <= n ; ++i )
            scanf( "%d" , weight + i );
        weight[0] = 0 ;
        sort( weight + 1 , weight + n + 1);
        for( i = 0 ; i <= n ; ++i )
            for( j = 1 ; j <= k ; ++j )
                dp[i][j] = 0xffffff;
        dp[0][0] = 0;
        for( i = 2 ; i <= n ; ++i ){
            for( j = 1 ; j * 2 <= i ; ++j ){
                dp[i][j] = min(dp[i-2][j-1]+(weight[i]-weight[i-1])*(weight[i]-weight[i-1]),dp[i-1][j]);
            }
        }
        printf( "%d\n" , dp[n][k] );
    }
    return 0;
}