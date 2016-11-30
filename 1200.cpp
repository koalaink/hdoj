#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(){
    int n , m , len , i , j , index ;
    char mm[205];
    char ans[25][25];
    // freopen( "0input.txt" , "r" , stdin );
    while( scanf( "%d" , &n ) , n ){
        scanf( "%s" , mm );
        len = strlen(mm);
        m = len/n ;
        index = 0 ;
        for( i = 1 ; i <= m ; ++i )
            for( j = 1 ; j <= n ; ++j )
                if( i%2 == 1 )
                    ans[i][j] = mm[index++] ;
                else
                    ans[i][n-j+1] = mm[index++];
        for( i = 1 ; i <= n ; ++i )
            for( j = 1 ; j <= len/n ; ++j )
                printf( "%c" , ans[j][i] );
        puts("");
    }
    return 0;
}