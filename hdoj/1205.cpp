#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int c[1000001];

int main(){
    long long t , n , i , sum , max ;

    scanf( "%I64d" , &t );
    while( t-- ){
        sum = 0 ;
        max = -1;
        scanf( "%I64d" , &n );
        for( i = 0 ; i < n ; ++i ){
            scanf( "%I64d" , c + i ) , sum += c[i] ;
            if( c[i] > max ) max = c[i] ;
        }
        sum -= max ;
        if( sum < max - 1 ) printf( "No\n" );
        else printf( "Yes\n" );
    }
}