#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    int t , len , i , tmp ;
    char s[105];
    int dp[105][2];
    scanf( "%d" , &t );
    while( t-- ){
        scanf( "%s" , s );
        len = strlen( s );
        memset( dp , 0 , sizeof(dp) );
        if( s[0] >= 'A' && s[0] <= 'Z' ) dp[0][0] = 2 , dp[0][1] = 2 ;
        else dp[0][0] = 1 , dp[0][1] = 2 ;
        for( i = 1 ; i < len ; ++i ){
            if( s[i] >= 'A' && s[i] <= 'Z' ){
                dp[i][0] = dp[i-1][0] + 2 < dp[i-1][1] + 2 ? dp[i-1][0] + 2 : dp[i-1][1] + 2 ;
                dp[i][1] = dp[i-1][0] + 2 < dp[i-1][1] + 1 ? dp[i-1][0] + 2 : dp[i-1][1] + 1 ;
            }
            else{
                dp[i][0] = dp[i-1][0] + 1 < dp[i-1][1] + 2 ? dp[i-1][0] + 1 : dp[i-1][1] + 2 ;
                dp[i][1] = dp[i-1][0] + 2 < dp[i-1][1] + 2 ? dp[i-1][0] + 2 : dp[i-1][1] + 2 ;
            }
        }
        dp[len-1][1]++;
        printf( "%d\n" , dp[len-1][0] < dp[len-1][1] ? dp[len-1][0] : dp[len-1][1] );
    }
}