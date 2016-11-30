#include<memory.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<vector>
using namespace std ;

const int MAX = 11 ;
int n ;
map<string ,vector< string> > matrix ;
map<string,bool> vis ;

bool dfs(string s , string e ){
	if( s.compare(e) == 0 )
		return true ;
	for( int i = 0 ; i < matrix[s].size() ; ++i ){
		string nex = matrix[s][i] ;
		if( !vis[nex] ){
			vis[nex] = true ;
			if( dfs(nex,e) ) return true ;
		}
	}
	return false ;
}

int main(){
	int cas = 1 ;
	string f , t ;
	string s , e ;
	int tmp ;
	while( scanf( "%d" , &n ) , n ){
		matrix.clear() ;
		vis.clear() ;
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%d" , &tmp ) ;
			s += tmp+'0' ;
		}
		for( int i = 0 ; i < n ; ++i ){
			scanf( "%d" , &tmp ) ;
			e += tmp+'0' ;
		}
		while( scanf( "%d" , &tmp ) , tmp>=0 ){
			f += tmp+'0' ;
			for( int i = 1 ; i < n ; ++i ){
				scanf( "%d" , &tmp ) ;
				f += tmp+'0' ;
			}
			for( int i = 0 ; i < n;  ++i ){
				scanf( "%d" , &tmp ) ;
				t += tmp+'0' ;
			}
			matrix[f].push_back(t) ;
			matrix[t].push_back(f) ;
			f = t = "" ;
		}
		if( dfs(s,e) )
			printf( "Maze #%d can be travelled\n" , cas++ ) ;
		else
			printf( "Maze #%d cannot be travelled\n" , cas++ ) ;
		s = e = "" ;
	}
	return 0 ;
}