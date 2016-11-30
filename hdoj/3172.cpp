#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;

map<string,int> name ;
int father[100001] ;
int son[100001] ;
int n , m ;

void init(){
	name.clear() ;
	for( n = 0 ; n < 100000 ; ++n ){
		father[n] = n ;
		son[n] = 1 ;
	}
	n = 1 ;
	return ;
}

int find( int x ){
	if( x != father[x] )
		father[x] = find(father[x]) ;
	return father[x] ;
}

void Union( int x , int y ){
	x = find(x) ;
	y = find(y) ;
	if( x != y ){
		father[y] = x ;
		son[x] += son[y] ;
		printf( "%d\n" , son[x] ) ;
	}
	else{
		printf( "%d\n" , son[x] ) ;
	}
	return ;
}


int main(){
	string s1 , s2 ;
	int t ;
	while( scanf( "%d" , &t ) != EOF ){
		while( t-- ){
			init() ;
			scanf( "%d" , &m ) ;
			while( m-- ){
				cin>>s1>>s2 ;
				if( name.find(s1) == name.end() ) name[s1] = n++ ;
				if( name.find(s2) == name.end() ) name[s2] = n++ ;
				Union(name[s1],name[s2]) ;
			}
		}
	}
	return 0 ;
}