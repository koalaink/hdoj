#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
    int n , m , i , j , tmp , sum ;
    int ans[1003];
    while( scanf( "%d%d" , &n , &m ) != EOF ){
        sum = 0;
        for( i = 1 ; i <= sqrt((double)n); ++i ){
            if( n%i ) continue;
            j = i ;
            while( j ){
                tmp = j % m ;
                sum += tmp * tmp ;
                j /= m ;
            }
            j = n / i ;
            if( j == i ) continue;
            while( j ){
                tmp = j % m ;
                sum += tmp * tmp ;
                j /= m ;
            }
        }
        i = 0 ;
        while( sum ){
            ans[i] = sum % m ;
            sum /= m ;
            ++i;
        }
        while( i-- ){
            if( ans[i] > 9 ) printf( "%c" , ans[i] - 10 + 'A' );
            else printf( "%d" , ans[i] );
        }
        printf( "\n" );
    }
}