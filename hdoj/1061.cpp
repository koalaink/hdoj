#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int t ;
    long long n ;
    int tmp ;
     int rm[10][4] = {{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};
    scanf( "%d" , &t );
    while( t-- ){
        scanf( "%I64d" , &n );
        tmp = n % 10 ;
        if( tmp == 0 || tmp == 1 || tmp == 5 || tmp == 6 )
            printf( "%d\n" , tmp );
        else if( tmp == 4 || tmp == 9 )
            printf( "%d\n" , rm[tmp][n%2] );
        else if( tmp == 2 || tmp == 3 || tmp == 7 || tmp == 8 )
            printf( "%d\n" , rm[tmp][n%4] );
    }
    return 0;
}