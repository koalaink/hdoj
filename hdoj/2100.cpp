#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    char a[205] , b[205] , ans[205] ;
    int tmp;
    int i , j , k , l1 , l2 ;
    while( scanf( "%s%s" , a , b ) != EOF ){
        l1 = strlen(a);
        l2 = strlen(b);
        i = l1 - 1;
        j = l2 - 1;
        k = l1>l2?l1:l2;
        ans[k+1] = '\0' ;
        tmp = 0;
        while( i>=0 && j>=0 ){
            ans[k--] = (char)( ( tmp + a[i] + b[j] - 2 * 'A' ) % 26 + 'A' );
            tmp = ( tmp + a[i] + b[j] - 2 * 'A' ) / 26 ;
            --i;
            --j;
        }
        if( i >= 0 ){
            while( i >= 0 ){
                ans[k--] = (char)( ( tmp + a[i] - 'A' ) % 26 + 'A' );
                tmp = ( tmp + a[i] - 'A' ) / 26 ;
                --i;
            }
        }else if( j >= 0 ){
            while( j >= 0 ){
                ans[k--] = (char)( ( tmp + b[j] - 'A' ) % 26 + 'A' );
                tmp = ( tmp + b[j] - 'A' ) / 26 ;
                --j;
            }
        }
        ans[k] = tmp + 'A' ;
        while( ans[k] == 'A' ) ++k;
        printf( "%s\n" , ans+k );
    }
}