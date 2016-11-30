/*
sample input:
2
3 3
3 4
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

int num[105] , len ;

int gcd( int x , int y ){
	if( y == 0 )
		return x ;
	else
		return gcd(y,x%y) ;
}

void big_mul( int x ){
	for( int i = 0 ; i < len ; ++i )
		num[i] *= x ;
	for( int i = 1 ; i < len ; ++i ){
		num[i] += num[i-1]/10 ;
		num[i-1] %= 10 ;
	}
	if( num[len-1]/10 ){
		num[len] = num[len-1]/10 ;
		num[len-1] %= 10 ;
		++len ;
	}
	return ;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	int t ;
	int m , n ;
	while( scanf( "%d" , &t ) != EOF ){
		while( t-- ){
			scanf( "%d%d" , &m , &n ) ;
			memset(num,0,sizeof(num)) ;
			num[0] = 1 ;
			len = 1 ;
			int a = n ; 
			int b ;
			for( int i = 0 ; i < n-1 ; ++i ){
				b = m ;
				int gc = gcd(a,b) ;
				a /= gc ;
				b /= gc ;
				big_mul(b) ;
			}
			printf( "%d/" , a ) ;
			for( int i = len-1 ; i >= 0 ; --i )
				printf( "%d" , num[i] ) ;
			printf( "\n" ) ;
		}
	}
	return 0 ;
}