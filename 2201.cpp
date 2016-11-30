/*
sample input:
2 1
11 3
 */
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	// freopen("0input.txt","r",stdin) ;
	int n , m ;
	while( scanf( "%d%d" , &n , &m ) != EOF ){
		printf( "%.02lf\n" , 1.0/n ) ;
	}
}