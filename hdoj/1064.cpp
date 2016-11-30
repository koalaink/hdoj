#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    double m , s ;
    // freopen( "0input.txt" , "r" , stdin );
    while( scanf( "%lf" , &m ) != EOF ){
        s = m ;
        for( int i = 1 ; i < 12 ; ++i ){
            scanf( "%lf" , &m );
            s += m;
        }
        printf( "$%.2lf\n" , s/12 );
    }
    return 0;
}