#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

struct ds{
    int num[105] ;
    int len ;
    void init( char s[105] = "0" ){
        memset( num , 0 , sizeof(num) );
        len = 0 ;
        int l = strlen(s) ;
        for( ; len < l ; ++len ){
            num[len] = s[l-1-len] - '0' ;
        }
        return ;
    }
    void plus( const ds& a , const ds& b ){
        this->init();
        int maxlen = a.len>b.len?a.len:b.len;
        for( len = 0 ; len < maxlen ; ++len )
            num[len] = a.num[len] + b.num[len] ;
        for( len = 0 ; len < maxlen ; ++len ){
            num[len+1] += num[len]/10 ;
            num[len] %= 10 ;
        }
        if( num[len] )
            ++len ;
        return ;
    }
    bool is_less_than_or_equal_to( const ds& a ){
        if( len != a.len )
            return len<a.len ;
        for( int i = len - 1 ; i >= 0 ; --i ){
            if( num[i] != a.num[i] )
                return num[i]<a.num[i] ;
        }
        return true;
    }
}fb[500];

int main(){
    fb[1].init("1");
    fb[2].init("2");
    int i , ans ;
    for( i = 3 ; i < 500 ; ++i )
        fb[i].plus(fb[i-1],fb[i-2]);
    char a[105] , b[105] ;
    ds aa , bb ;
    while( scanf( "%s%s" , a , b ) ){
        if( strcmp(a,"0") == 0 && strcmp(b,"0") == 0 )
            break;
        aa.init(a);
        bb.init(b);
        ans = 0;
        for( i = 0 ; i < 500 ; ++i )
            if( aa.is_less_than_or_equal_to(fb[i]) && fb[i].is_less_than_or_equal_to(bb) )
                ++ans;
        printf( "%d\n" , ans );
    }
    return 0;
}