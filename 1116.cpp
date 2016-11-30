#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int MAX = 26 ;
int father[26] ;
bool has[26] ;
int out[26] ;
int in[26] ;
int root ;
int n ;

void Init(){
	root = 0 ;
	for( int i = 0 ; i < 26 ; ++i ){
		father[i] = i ;
		has[i] = false ;
		out[i] = in[i] = 0 ;
	}
	return ;
}

int findfather( int x ){
	if( x != father[x] )
		father[x] = findfather(father[x]) ;
	return father[x] ;
}

void Union( int s , int e ){
	s = findfather(s) ;
	e = findfather(e) ;
	if( s != e ){
		father[s] = e ;
	}
	return ;
}

int main(){
	// freopen( "0input.txt" , "r" , stdin ) ;
	int p[26] ;
	char str[1005] ;
	int T , a , b ;
	scanf( "%d" , &T ) ;
	while( T-- ){
		scanf( "%d" , &n ) ;
		Init() ;
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%s" , str ) ;
			a = str[0] - 'a' ;
			b = str[strlen(str)-1] - 'a' ;
			Union(a,b) ;
			out[a]++ ;
			in[b]++ ;
			has[a] = has[b] = true ;
		}
		int i , j ;
		for( i = 0 , j = 0 ; i < 26 ; ++i ){
			if( has[i] && findfather(i) == i )
				root++ ;
			if( has[i] && out[i] != in[i] )
				p[j++] = i ;
		}
		if( root > 1 ){
			printf( "The door cannot be opened.\n" ) ;
			continue ;
		}
		if( j == 0 ){
			printf( "Ordering is possible.\n" ) ;
			continue ;
		}
		if( j == 2 && (out[p[0]]-in[p[0]]==1 && in[p[1]]-out[p[1]]==1 || out[p[1]]-in[p[1]]==1 && in[p[0]]-out[p[0]]==1 ) )
			printf( "Ordering is possible.\n" ) ;
		else
			printf( "The door cannot be opened.\n" ) ;
	}
	return 0 ;
}