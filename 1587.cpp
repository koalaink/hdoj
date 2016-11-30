#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n , m , i , p , min ;
    while( scanf( "%d%d" , &n , &m ) != EOF ){
        min =  10000000 ;
        for( i = 0 ; i < n ; ++i ){
            scanf( "%d" , &p );
            if( p < min ) min = p ;
        }
        printf( "%d\n" , m/min );
    }
}