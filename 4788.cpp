/*
sample input:
2
100[MB]
1[B]
 */
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;

int main(){
	int t ;
	// freopen("0input.txt","r",stdin) ;
	scanf( "%d" , &t ) ;
	int cas = 1 ;
	while( t-- ){
		int n ;
		char s[10];
		scanf( "%s" , s ) ;
		int i ;
		int x ;
		for( i = 0 ; i < strlen(s) ; ++i ){
			if( s[i] == '[' ){
				i++ ;break;
			}
		}
		if( s[i] == 'B' ){
			x = 1 ;
		}
		else if( s[i] == 'K' ){
			x = 2 ;
		}
		else if( s[i] == 'M' ){
			x = 3 ;
		}
		else if( s[i] == 'G' ){
			x = 4 ;
		}
		else if( s[i] == 'T' ){
			x = 5 ;
		}
		else if( s[i] == 'P' ){
			x = 6 ;
		}
		else if( s[i] == 'E' ){
			x = 7 ;
		}
		else if( s[i] == 'Z' ){
			x = 8 ;
		}
		else if( s[i] == 'Y' ){
			x = 9 ;
		}
		double kk = 1000.0/1024.0 ;
		double ans = 1.0;
		while( --x ){
			ans *= kk ;
		}
		printf( "Case #%d: %.02lf%%\n" , cas++ , (1-ans)*100 ) ;
	}
	return 0 ;
}