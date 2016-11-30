#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<string>
using namespace std;

const int INF = 0xffffff ;

int s[1000001];
int t[10001];
int Next[10001];
int n , m ;

void getNEXT(){
	int k = -1 ;
	Next[0] = -1 ;
	int i = 0 ;
	while( i < m ){
		if( k == -1 || t[i] == t[k] ){
			++k;
			++i;
			if( t[i] == t[k] )
				Next[i] = Next[k] ;
			else
				Next[i] = k ;
		}
		else
			k = Next[k] ;
	}
	return ;
}

int KMP(){
	int index , i , j ;
	index = i = j = 0 ;
	getNEXT();
	while( i < n && j < m ){
		if( s[i] == t[j] ){
			++i ;
			++j ;
		}
		else{
			index += j - Next[j] ;
			if( Next[j] != -1 )
				j = Next[j] ;
			else{
				j = 0 ;
				++i ;
			}
		}
	}
	if( j == m )
		return index ;
	else
		return -1 ;
}

int main(){
	int T;
	//freopen( "0input.txt" , "r" , stdin );
	scanf( "%d" , &T );
	while( T-- ){
		scanf( "%d%d" , &n , &m );
		memset( s , INF , sizeof(s) );
		memset( t , INF , sizeof(t) );
		for( int i = 0 ; i < n ; ++i )
			scanf( "%d" , s + i );
		for( int i = 0 ; i < m ; ++i )
			scanf( "%d" , t + i );
		int ans = KMP();
		ans += (ans==-1?0:1) ;
		printf( "%d\n" , ans );
	}
	return 0;
}