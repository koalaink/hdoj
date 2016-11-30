#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

const int MAX = 1001;
int l1 , l2 ;
int dp[MAX][MAX];
char s1[MAX] , s2[MAX];

void zcggzxl(){
    memset( dp , 0 , sizeof(dp) );
    for( int i = 0 ; i < l1 ; ++i )
        for( int j = 0 ; j < l2 ; ++j )
            if( s1[i] == s2[j] )
                dp[i+1][j+1] = dp[i][j] + 1;
            else 
                dp[i+1][j+1] = dp[i+1][j] < dp[i][j+1] ? dp[i][j+1] : dp[i+1][j] ;
    return ;
}

int main(){
    while( scanf( "%s%s" , s1 , s2 ) != EOF ){
        l1 = strlen(s1);
        l2 = strlen(s2);
        zcggzxl();
        printf( "%d\n" , dp[l1][l2] );
    }
    return 0;
}