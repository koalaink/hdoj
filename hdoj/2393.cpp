#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
	int t , i , a , b , c ;
	//freopen( "0input.txt" , "r" , stdin );
	scanf( "%d" , &t );
	for( i = 1 ; i <= t ; ++i ){
		scanf( "%d%d%d" , &a , &b , &c );
		printf( "Scenario #%d:\n" , i );
		if( a*a+b*b == c*c || a*a+c*c == b*b || b*b+c*c == a*a )
			printf( "yes\n" );
		else
			printf( "no\n" );
		puts("");
	}
	return 0;
}