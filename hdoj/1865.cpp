#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

struct ds{
    int num[2000];
    int len ;
    void inif( int a = 0 ){
        memset( num , 0 , sizeof(num) );
        len = 0 ;
        while( a ){
            num[len++] = a % 100 ;
            a /= 100 ;
        }
        return ;
    }
    void plus( const ds& a , const ds& b ){
        this->inif();
        int maxlen = a.len>b.len?a.len:b.len;
        for( int i = 0 ; i < maxlen ; ++i )
            num[i] = a.num[i] + b.num[i] ;
        for( int i = 0 ; i < maxlen ; ++i ){
            num[i+1] += num[i] / 100 ;
            num[i] %= 100 ;
        }
        if( num[maxlen] )
            len = maxlen + 1;
        else
            len = maxlen ;
        return ;
    }
    void print(){
        printf( "%d" , num[len-1] );
        for( int i = len - 2 ; i >= 0 ; --i )
            printf( "%02d" , num[i] );
        printf( "\n" );
        return ;
    }
}fb[205];

int main(){
    int t , len ;
    fb[0].inif(0);
    fb[1].inif(1);
    fb[2].inif(2);
    for( t = 3 ; t < 205 ; ++t )
        fb[t].plus( fb[t-1] , fb[t-2] );
    char s[205];
    while( scanf( "%d" , &t ) != EOF ){
        while( t-- ){
            scanf( "%s" , s );
            len = strlen(s);
            fb[len].print();
        }
    }
    return 0;
}