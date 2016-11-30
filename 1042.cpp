#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int ans[8001];
    int n , i , j ;
    while( scanf( "%d" , &n ) != EOF ){
        if( n == 0 || n == 1 ){
            printf( "1\n" );
            continue;
        }
        memset( ans , 0 , sizeof(ans) );
        ans[0] = 1 ;
        for( i = 2 ; i <= n ; ++i ){
            for( j = 0 ; j < 8000 ; ++j )
                ans[j] *= i ;
            for( j = 0 ; j < 8000 ; ++j ){
                ans[j+1] += ans[j] / 100000 ;
                ans[j] %= 100000 ;
            }
        }
        for( i = 8000 ; i >= 0 && !ans[i] ; --i );
        printf( "%d" , ans[i--] );
        for( ; i >= 0 ; --i ){
            printf( "%05d" , ans[i] );
        }
        printf( "\n" );
    }
    return 0;
}
