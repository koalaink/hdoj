#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<queue>
using namespace std;

const int INF = 0x7fffffff ;
const int MAX = 10 ;
char map[MAX][MAX] ;
bool hash[MAX][MAX][2] ;
int dir[4][2] = {1,0,-1,0,0,1,0,-1} ;
int n , m , t ;
int sx , sy ;
int ans ;

struct node{
	int x , y ;
	int step ;
	int key ;
	bool check(){
		if( x<0||x>=n || y<0||y>=m || map[x][y]=='#' )
			return false ;
		return true ;
	}
};
node s ;

bool bfs(){
	memset(hash,false,sizeof(hash)) ;
	queue<node> q ;
	node cur , nex ;
	hash[s.x][s.y][s.key] = true ;
	q.push(s) ;
	while( !q.empty() ){
		cur = q.front() ;
		q.pop() ;
		if( map[cur.x][cur.y] == 'E' && cur.key ){
			return false ;
		}
		if( cur.step >= t ) continue ;
		for( int i = 0 ; i < 4 ; ++i ){
			nex = cur ;
			nex.x += dir[i][0] ;
			nex.y += dir[i][1] ;
			nex.step++ ;
			if( nex.check() ){
				if( map[nex.x][nex.y] == 'J' )
					nex.key = true ;
				if( !hash[nex.x][nex.y][nex.key] ){
					hash[nex.x][nex.y][nex.key] = true ;
					q.push(nex) ;
				}
			}
		}
	}
	return true ;
}

bool dfs( int deep ){

	if( !deep ) return bfs() ;

	for( int i = 0 ; i < n ; ++i ){
		for( int j = 0 ; j < m ; ++j ){
			char ch = map[i][j] ;
			if( ch == 'S' || ch == 'E' )
				continue ;
			map[i][j] = '#' ;
			if( dfs(deep-1) ) return true ;
			map[i][j] = ch ;
		}
	}

	return false;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	int T ;
	while( scanf( "%d" , &T ) != EOF ){
		while( T-- ){
			scanf( "%d%d%d" , &n , &m , &t ) ;
			for( int i = 0 ; i < n ; ++i ){
				char tmp[MAX] ;
				scanf( "%s" , tmp ) ;
				for( int j = 0 ; j < m ; ++j ){
					map[i][j] = tmp[j] ;
					if( tmp[j] == 'S' )
						s.x = i , s.y = j ;
				}
			}
			s.step = 0 ;s.key = 0 ;
			if( dfs(0) ) puts("0") ;
			else if( dfs(1) ) puts("1") ;
			else if( dfs(2) ) puts("2") ;
			else if( dfs(3) ) puts("3") ;
			else puts("4") ;
		}
	}
	return 0 ;
}