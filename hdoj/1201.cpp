#include<iostream>
#include<stdio.h>
using namespace std;

bool fun(int y){
    if( y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0) )
        return true;
    return false;
}

int main(){
    int t , i , year , month , day , ans ;
    scanf( "%d" , &t );
    while( t-- ){
        scanf( "%d-%d-%d" , &year , &month , &day );
        ans = 365 * 18 ;
        if( !fun( year + 18 ) && month == 2 && day == 29 ){
            printf( "-1\n" );
            continue;
        }
        if( fun( year ) && (month < 2 || month == 2 && day <= 28 ) )
            ++ans;
        if( fun( year + 18 ) && (month > 2 || month == 2 && day == 29 ) )
            ++ans;
        for( i = year + 1 ; i < year + 18 ; ++i )
            if( fun( i ) )
                ++ans;
        printf( "%d\n" , ans );
    }
}