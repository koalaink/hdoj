#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int min[1005];
    int n , i , j , tmp ;
    while( scanf( "%d" , &n ) != EOF ){
        memset( min , 0 , sizeof(min) );
        min[0] = 30001 ;
        i = 1 ; 
        while( n-- ){
            scanf( "%d" , &tmp );
            for( j = 0 ; j <= i ; ++j )
                if( min[j] > tmp ){
                    min[j] = tmp ;
                    break;
                }
            if( j > i ) min[++i] = tmp ;
        }
        printf( "%d\n" , i );
    }
}