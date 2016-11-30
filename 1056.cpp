#include<iostream>
#include<stdio.h>
using namespace std;

bool fun(int y){
    if( y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0) )
        return true;
    return false;
}

int main(){
    int n ;
    double sum ;
    double len ;
    while( scanf( "%lf" , &len ) ){
        if( len == 0 ) break;
        sum = 0;
        n = 0;
        while( sum < len ){
            ++n;
            sum += 1.0/(n+1) ;
        }
        printf( "%d card(s)\n" , n );
    }
}