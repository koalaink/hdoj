#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<queue>
using namespace std;

#define MAX 11

int n ;
char s1[MAX] , s2[MAX] ;
char map[MAX][MAX][MAX] ;
bool visit[MAX][MAX][MAX] ;
int dir[6][3] = { {0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} } ;

struct node{
	int x , y , z ;
	int step ;
	bool check(){
		if( x<0||x>=n||y<0||y>=n||z<0||z>=n||map[z][x][y]=='X' )
			return false ;
		return true ;
	}
};

void bfs( node st , node en ){
	memset( visit , false , sizeof(visit) ) ;
	node now , next ;
	queue<node> q ;
	st.step = 0 ;
	visit[st.x][st.y][st.z] = true ;
	q.push(st) ;
	while( !q.empty() ){
		now = q.front() ;
		q.pop() ;
		if( now.x == en.x && now.y == en.y && now.z == en.z ){
			printf( "%d %d\n" , n , now.step ) ;
			return ;
		}
		for( int i = 0 ; i < 6 ; ++i ){
			next.x = now.x + dir[i][0] ;
			next.y = now.y + dir[i][1] ; 
			next.z = now.z + dir[i][2] ;
			next.step = now.step + 1 ;
			if( next.check() && !visit[next.x][next.y][next.z] ){
				visit[next.x][next.y][next.z] = true ;
				q.push(next) ;
			}
		}
	}
	printf( "NO ROUTE\n" ) ;
	return ;
}

int main(){
	// freopen( "0input.txt" , "r" , stdin ) ;
	node st , en ;
	while( scanf( "%s %d" , s1 , &n ) != EOF ){
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < n ; ++j )
				scanf( "%s" , map[i][j] ) ;
		scanf( "%d%d%d" , &st.x , &st.y , &st.z ) ;
		scanf( "%d%d%d" , &en.x , &en.y , &en.z ) ;
		scanf( "%s" , s2 ) ;
		bfs(st,en) ;
	}
	return 0 ;
}