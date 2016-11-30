#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int a ;
	int tmp , e , ans ;
	while( scanf( "%d" , &a ) ){
		if( a == -1 )
			break;
		e = a/30;
		tmp = a - e*30;
		ans = 3 - e ;
		if( ans < 0 ){
			ans += 12 ;
		}
		if( tmp == 0 )
			printf( "Exactly %d o'clock\n" , ans );
		else
			printf( "Between %d o'clock and %d o'clock\n" , (ans-1)<0?(ans-1+12):(ans-1) , ans );
	}
	return 0;
}