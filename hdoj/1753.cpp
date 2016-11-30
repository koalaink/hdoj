#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

struct ds{
    int a[405];
    int b[405];
    int alen , blen ;
    void init( char s[405] = "0" ){
        memset( a , 0 , sizeof(a) );
        memset( b , 0 , sizeof(b) );
        alen = 0 ;
        blen = 0 ;
        int len = strlen(s) , i ;
        for( i = 0 ; i < len ; ++i ){
            if( s[i] == '.' )
                break;
        }
        alen = i ;
        for( i = 0 ; i < alen ; ++i )
            a[i] = s[alen-1-i] - '0' ;
        blen = len - alen - 1 ;
        for( i = 0 ; i < blen ; ++i )
            b[i] = s[alen+1+i] - '0' ;
        this->cutzero();
        return ;
    }
    void plus( const ds& x , const ds& y ){
        this->init();
        int i ;
        blen = x.blen>y.blen?x.blen:y.blen ;
        for( i = blen - 1 ; i >= 0 ; --i )
            b[i] = x.b[i] + y.b[i];
        for( i = blen - 1 ; i > 0 ; --i ){
            b[i-1] += b[i]/10 ;
            b[i] %= 10;
        }
        a[0] += b[i]/10;
        b[i] %= 10;
        alen = x.alen>y.alen?x.alen:y.alen;
        for( i = 0 ; i < alen ; ++i )
            a[i] += (x.a[i] + y.a[i]) ;
        for( i = 0 ; i < alen ; ++i ){
            a[i+1] += a[i]/10 ;
            a[i] %= 10 ;
        }
        if( a[alen] ) ++alen ;
        this->cutzero();
        return ;
    }
    void cutzero(){
        while( alen > 1 && a[alen-1] == 0 ) --alen;
        while( blen > 0 && b[blen-1] == 0 ) --blen;
        return ;
    }
    void print(){
        this->cutzero();
        for( int i = alen - 1 ; i >= 0 ; --i )
            printf( "%d" , a[i] );
        if( blen > 0 )
            printf( "." ) ;
        for( int i = 0 ; i < blen ; ++i )
            printf( "%d" , b[i] );
        printf( "\n" );
    }
};

int main(){
    char x[405] , y[405] ;
    ds xx , yy , zz ;
    while( scanf( "%s%s" , x , y ) != EOF ){
        xx.init(x);
        yy.init(y);
        zz.plus(xx,yy);
        zz.print();
    }
    return 0;
}