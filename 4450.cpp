/*
sample input:
4
1 2 3 4
3
3 3 3
0
 */
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int n , sum ;
	while( scanf( "%d" , &n ) , n ){
		sum = 0 ;
		while( n-- ){
			int tmp ;
			scanf( "%d" , &tmp ) ;
			sum += tmp*tmp ;
		}
		printf( "%d\n" , sum ) ;
	}
	return 0 ;
}