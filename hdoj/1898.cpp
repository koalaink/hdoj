#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n , a , b , t ;
    int x , s ;
    scanf( "%d" , &n );
    while( n-- ){
        x = s = 0;
        scanf( "%d%d%d" , &a , &b , &t );
        if( t % a == 0 )
            s = t ;
        else
            s = t / a * a ;
        if( t % b == 0 )
            x = t ;
        else
            x = t / b * b ;
        printf( "%s\n" , s > x ? "Sempr!" : ( s < x ? "Xiangsanzi!" : "Both!" ) ) ;
    }
}