#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int a , b , c ;
	// freopen( "0input.txt" , "r" , stdin );
	scanf( "%d%d%d" , &a , &b , &c );
	if( a <= 168 )
		printf( "CRASH %d\n" , a );
	else if( b <= 168 )
		printf( "CRASH %d\n" , b );
	else if( c <= 168 )
		printf( "CRASH %d\n" , c );
	else
		printf( "NO CRASH\n" );
	return 0;
}