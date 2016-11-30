#include<iostream>
#include<stdio.h>
using namespace std ;

#define MAX 100005

struct Node{
	int x , y ;
};

int father[MAX] ;
Node edge[MAX] ;
bool has[MAX] ;
int son[MAX] ;
int in[MAX];
int n , m , cnt ;

void mymax( int a , int b , int& c ){
	if( a > b && a > c ){
		c = a ;
		return ;
	}
	if( b > a && b > c ){
		c = b ;
		return ;
	}
	return ;
}

void Init( int& root ){
	n = m = root = 0 ;
	for( int i = 1 ; i < MAX ; ++i ){
		in[i] = 0 ;
		has[i] = false ;
		father[i] = i ;
	}
	return ;
}

int find( int p ){
	if( p != father[p] )
		father[p] = find(father[p]) ;
	return father[p] ;
}

void Union( int x , int y ){
	++m ;
	x = find(x) ;
	y = find(y) ;
	if( x !=  y ){
		father[y] = x ;
		/*
		if( son[x] >= son[y] ){
			father[y] = x ;
			son[x] += son[y] ;
		}
		else{
			father[x] = y ;
			son[y] += son[x] ;
		}
		*/
	}
	return ;
}

int main(){
	int flag1 , flag2 ;
	int cas = 1 ;
	int tmp ;
	int root ;
	int a , b , i ;
	while( scanf( "%d%d" , &a , &b ) ){
		if( a < 0 && b < 0 )
			break ;
		if( a == 0 && b == 0 ){
			printf( "Case %d is a tree.\n" , cas++ ) ;
			continue ;
		}
		Init(root) ;
		Union(a,b) ;
		mymax(a,b,n) ;
		has[a] = has[b] = true ;
		in[b]++;
		while( scanf( "%d%d" , &a , &b ) , a || b ){
			Union(a,b) ;
			mymax(a,b,n) ;
			has[a] = has[b] = true ;
			in[b]++ ;
		}
		flag1 = flag2 = 0 ;
		for( int i = 1 ; i <= n ; ++i ){
			if( has[i] && in[i] > 1 ){
				flag1 = 1 ;
				break ;
			}
		}
		for( int i = 1 ; i <= n ; ++i ){
			if( has[i] && in[i] == 0 ){
				flag2++ ;
			}
		}
		if( flag1 || flag2 != 1 ){
			printf( "Case %d is not a tree.\n" , cas++ ) ;
			continue ;
		}
		for( int i = 1 ; i <= n ; ++i ){
			if( has[i] && find(i) == i ) root++ ;
		}
		if(root != 1 )
			printf( "Case %d is not a tree.\n" , cas++ ) ;  
        else
			printf( "Case %d is a tree.\n" , cas++ ) ;
	}
	return 0 ;
}