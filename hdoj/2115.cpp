#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

struct g{
	char name[20];
	int m , s ;
}p[25];

bool cmp( const g a , const g b ){
	if( a.m != b.m )
		return a.m<b.m;
	if( a.s != b.s )
		return a.s<b.s;
	return (strcmp(a.name,b.name) < 0 );
}

int main(){
	int n ;
	int t = 1;
	while( scanf( "%d" , &n ) , n ){
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%s %d:%d" , p[i].name , &p[i].m , &p[i].s );
		}
		sort(p,p+n,cmp);
		if( t != 1 ) printf( "\n" );
		printf( "Case #%d\n" , t );
		printf( "%s 1\n" , p[0].name );
		int count = 1;
		for( int i = 1 ; i < n ; ++i ){
			if( p[i].m == p[i-1].m && p[i].s == p[i-1].s )
				printf( "%s %d\n" , p[i].name , count );
			else{
				printf( "%s %d\n"  , p[i].name , i+1 );
				count = i + 1; 
			}
		}
		++t;
	}
	return 0;
}