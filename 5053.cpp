/*
sample input:
2
1 3
2 5
 */
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int t , cas ;
    long long a , b ;
    // freopen("0input.txt","r",stdin) ;
    scanf( "%d" , &t ) ;
    cas = 1 ;
    while( t-- ){
    	scanf( "%I64d%I64d" , &a , &b ) ;
    	a-- ;
    	long long ans = (b*(b+1)/2)*(b*(b+1)/2)-(a*(a+1)/2)*(a*(a+1)/2) ;
    	printf( "Case #%d: %I64d\n" , cas++ , ans ) ;
    }
}