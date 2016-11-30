/*
sample input:
4 5 17
@A.B.
a*.*.
*..*^
c..b*

4 5 16
@A.B.
a*.*.
*..*^
c..b*

 */

#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<queue>
#include<map>
using namespace std;

const int INF = 0x7fffffff ;
const int MAX = 25 ;
bool vis[MAX][MAX][1025] ;
int dir[4][2] = {0,1,0,-1,1,0,-1,0} ;
int sx , sy , ex , ey ;
int n , m , t ;
int ans ;

struct node{
	int x , y ;
	int step ;
	int key ;
	char map[MAX][MAX] ;
	bool check(){
		if( x<0||x>=n || y<0||y>=m || map[x][y]=='*' )
			return false ;
		return true ;
	}
	bool hasKey( int index ){
		if( key&(1<<index) )
			return true ;
		return false ;
	}
	void addKey( int index ){
		key = key|(1<<index) ;
		return ;
	}
};
node cur , nex ;

int bfs(){
	queue<node> q ;
	cur.x = sx ;
	cur.y = sy ;
	cur.step = 0 ;
	cur.key = 0 ;
	vis[sx][sy][0] = true ;
	q.push(cur) ;
	while( !q.empty() ){
		cur = q.front() ;
		q.pop() ;
		if( cur.x == ex && cur.y == ey ){
			if( cur.step < t )
				return cur.step ;
		}
		if( cur.step >= t ){
			continue ;
		}
		for( int i = 0 ; i < 4 ; ++i ){
			nex = cur ;
			nex.x += dir[i][0] ;
			nex.y += dir[i][1] ;
			nex.step++ ;
			if( nex.check() ){
				if( cur.map[nex.x][nex.y]>='a' && cur.map[nex.x][nex.y]<='j' ){
					nex.addKey(cur.map[nex.x][nex.y]-'a') ;
					if( !vis[nex.x][nex.y][nex.key] ){
						vis[nex.x][nex.y][nex.key] = true ;
						q.push(nex) ;
					}
				}
				else if( cur.map[nex.x][nex.y]>='A' && cur.map[nex.x][nex.y]<='J' ){
					if( nex.hasKey(cur.map[nex.x][nex.y]-'A') && !vis[nex.x][nex.y][nex.key] ){
						vis[nex.x][nex.y][nex.key] = true ;
						q.push(nex) ;
					}
				}
				else{
					if( !vis[nex.x][nex.y][nex.key] ){
						vis[nex.x][nex.y][nex.key] = true ;
						q.push(nex) ;
					}
				}
			}
		}
	}
	return -1;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	while( scanf( "%d%d%d" , &n , &m , &t ) != EOF ){
		for( int i = 0 ; i < n ; ++i ){
			char tmp[MAX] ;
			scanf( "%s" , tmp );
			for( int j = 0 ; j < m ; ++j ){
				cur.map[i][j] = tmp[j] ;
				if( tmp[j] == '@' )
					sx = i , sy = j ;
				else if( tmp[j] == '^' )
					ex = i , ey = j ;
			}
		}
		memset(vis,false,sizeof(vis)) ;
		ans = bfs() ;
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}