/*
sample input:
4
1 2 10 1
1
19
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
#define LL long long
#define MAX 1005
#define M 1000003
using namespace std;

int c[MAX][MAX] , arr[55] ;

void init(){
	c[0][0] = 1 ;
	c[1][0] = c[1][1] = 1 ;
	for( int i = 2 ; i < MAX ; ++i ){
		c[i][0] = 1 ;
		for( int j = 1 ; j <= i ; ++j ){
			c[i][j] = (c[i-1][j]+c[i-1][j-1]) % M ;
		}
	}
	return ;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	init() ;
	int n , tmp , index ;
	while( scanf( "%d" , &n ) != EOF ){
		memset(arr,0,sizeof(arr)) ;
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%d" , &tmp ) ;
			index = 1 ;
			while( tmp ){
				arr[index] += tmp&1 ;
				tmp = tmp>>1 ;
				index++ ;
			}
		}
		for( int i = 1 ; i <= n ; ++i ){
			int ans = 0 ;
			for( int j = 1 ; j <= 32 ; ++j ){
				for( int k = 1 ; k <= i ; k += 2 ){
					if( arr[j] < k || n-arr[j] < i-k ) continue ;
					ans += ((((LL)c[arr[j]][k]*c[n-arr[j]][i-k])%M)*(1<<(j-1)))%M ;
					ans %= M ;
				}
			}
			i>1?printf(" "):0;
			printf( "%d" , ans ) ;
		}
		printf("\n") ;
	}
	return 0 ;
}