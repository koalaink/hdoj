/*
sample input:
5
1
2
3
4
5
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

struct BigInt{
    const static int MOD = 10000 ;
    const static int MLEN = 4 ;
    int arr[505] , len ;

    BigInt(){
        memset(arr,0,sizeof(arr)) ;
        len = 1 ;
    }

    BigInt( long long value ){
        memset(arr,0,sizeof(arr)) ;
        len = 0 ;
        do{
            arr[len++] = value % MOD ;
            value /= MOD ;
        }while( value ) ;
    }

    BigInt( const char s[] ){
        memset(arr,0,sizeof(arr)) ;
        int L = strlen(s) ;
        len = L / MLEN ;
        if( L % MLEN ) len++ ;
        int index = 0 ;
        for( int i = L-MLEN ; i > -MLEN ; i -= MLEN ){
            int tmp = 0 , j = 0 ;
            if( i < 0 ) j = -i ;
            for( ; j < MLEN ; ++j )
                tmp = tmp*10 +s[i+j]-'0' ;
            arr[index++] = tmp ;
        }
    }

    bool operator <(const BigInt &b ) const {
        if( len != b.len ) return len<b.len ;
        int i = len-1 ;
        while( i>0 && arr[i]==b.arr[i]) --i ;
        return arr[i]<b.arr[i] ;
    }

    bool operator >(const BigInt &b ) const {
        if( len != b.len ) return len>b.len ;
        int i = len-1 ;
        while( i>0 && arr[i]==b.arr[i]) --i ;
        return arr[i]>b.arr[i] ;
    }

    bool operator ==(const BigInt &b ) const {
        if( len != b.len ) return false ;
        for( int i = len-1 ; i >= 0 ; --i ){
            if( arr[i] != b.arr[i] ) return false ;
        }
        return true ;
    }

    BigInt operator +(const BigInt &b ) const {
        BigInt res ;
        res.len = len>=b.len?len:b.len ;
        for( int i = 0 ; i <= res.len ; ++i ){
            res.arr[i] += arr[i] + b.arr[i] ;
            res.arr[i+1] += res.arr[i] / MOD ;
            res.arr[i] %= MOD ;
        }
        if( res.arr[res.len] > 0 ) res.len++ ;
        return res ;
    }

    BigInt operator -(const BigInt &b ) const {
        BigInt res ;
        res.len = len ;
        int del = 0 ;
        for( int i = 0 ; i < res.len ; ++i ){
            int tmp = arr[i] - b.arr[i] - del ;
            if( tmp >= 0 ){
                del = 0 ;
                res.arr[i] = tmp ;
            }
            else{
                del = 1 ;
                res.arr[i] += MOD ;
            }
        }
        while( res.len > 0 && res.arr[res.len-1] == 0 ) res.len-- ;
        return res ;
    }

    BigInt operator *(const BigInt &b ) const {
        BigInt res ;
        for( int i = 0 ; i < len ; ++i ){
            int up = 0 ;
            for( int j = 0 ; j < b.len ; ++j ){
                res.arr[i+j] += arr[i]*b.arr[j] + up ;
                up = res.arr[i+j] / MOD ;
                res.arr[i+j] %= MOD ;
            }
            if( up )
                res.arr[i+b.len] = up ;
        }
        res.len = len + b.len ;
        while( res.len && res.arr[res.len-1] == 0 ) res.len-- ;
        return res ;
    }

    void toString(){
        // 04 = MLEN
        printf( "%d" , arr[len-1] ) ;
        for( int i = len-2 ; i >= 0 ; --i )
            printf( "%04d" , arr[i] ) ;
        puts("") ;
    }
};

int main(){
    // freopen("0input.txt","r",stdin) ;
    int t , cas ;
    long long n ;
    scanf( "%d" , &t ) ;
    cas = 1 ;
    while( t-- ){
        scanf( "%I64d" , &n ) ;
        BigInt ans = (BigInt(n)*BigInt(8*n-7))+1 ;
        printf( "Case #%d: " , cas++ ) ;
        ans.toString() ;
    }
    return 0 ;
}