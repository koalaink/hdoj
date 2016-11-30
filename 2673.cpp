#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int a[10005];

int main(){
    int n , i , j ;
    while( scanf( "%d" , &n ) != EOF ){
        for( i = 0 ; i < n ; ++i )
            scanf( "%d" , a + i );
        sort( a , a + n );
        printf( "%d" , a[n-1] );
        i = 0 ; j = n - 2 ;
        while( i != j && i != j + 1 ){
            printf( " %d %d" , a[i] , a[j] ) ;
            ++i;
            --j;
        }
        if( i == j ) printf( " %d" , a[i] );
        puts("");
    }
    return 0;
}