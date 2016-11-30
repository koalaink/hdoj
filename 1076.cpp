#include<iostream>
#include<stdio.h>
using namespace std;

bool leapyear(int year){
    if( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0) )
        return true;
    return false;
}

int main(){
    int t , year , n , i ;
    scanf( "%d" , &t );
    while( t-- ){
        scanf( "%d%d" , &year , &n );
        i = 0;
        while( n ){
            if( leapyear(year+i) )
                --n;
            ++i;
        }
        printf( "%d\n" , year + i - 1 );
    }
}