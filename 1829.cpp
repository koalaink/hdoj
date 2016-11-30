#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 2005

int father[MAX] ;
int sex[MAX] ;
int son[MAX] ;
int n , m ;

void Init( bool& flag ){
	flag = false ;
	for( int i = 1 ; i <= n ; ++i ){
		father[i] = i ;
		sex[i] = 0 ;
		son[i] = 1 ;
	}
	return ;
}

int find( int x ){
	if( father[x] != x )
		father[x] = find(father[x]) ;
	return father[x] ;
}

void Union( int x , int y ){
	x = find(x) ;
	y = find(y) ;
	if( x != y ){
		if( son[x] >= son[y] ){
			father[y] = x ;
			son[x] += son[y] ;
		}
		else{
			father[x] = y ;
			son[y] += son[x] ;
		}
	}
	return ;
}

int main(){
	// freopen( "0input.txt" , "r" , stdin ) ;
	int a , b ;
	bool flag ;
	int cas = 1 , T ;
	bool blank = false ;
	scanf( "%d" , &T ) ;
	while( T-- ){
		scanf( "%d%d" , &n , &m ) ;
		Init(flag) ;
		while( m-- ){
			scanf( "%d%d" , &a , &b ) ;
			if( flag ) continue ;
			if( find(a) == find(b) ){
				flag = true ;
				continue ;
			}
			else{
				if( sex[a] == 0 )
					sex[a] = b ;
				else
					Union(sex[a],b) ;
				if( sex[b] == 0 )
					sex[b] = a ;
				else
					Union(sex[b],a) ;
			}
		}
		printf( "Scenario #%d:\n" , cas++ ) ;
		if( flag )
			printf( "Suspicious bugs found!\n" ) ;
		else
			printf( "No suspicious bugs found!\n" ) ;
		printf( "\n" ) ;
	}
	return 0 ;
}