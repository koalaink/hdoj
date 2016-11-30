#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int n ;
	int count;
	while( scanf( "%d" , &n ) , n ){
		count = 0;
		while( n != 1 ){
			if( n % 2 == 0 ) n /= 2;
			else n = (3*n+1)/2;
			count++;
		}
		printf( "%d\n" , count);
	}
	return 0;
}