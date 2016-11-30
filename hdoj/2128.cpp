#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<queue>
using namespace std ;

const int INF = 0x7fffffff ;
const int MAX = 10 ;
char map[MAX][MAX] ;
int vis[MAX][MAX][MAX*MAX*MAX] ;
int dir[4][2] = {0,1,0,-1,1,0,-1,0} ;
int n , m ;
int sx , sy , ex , ey ;
int ans ;

struct node{
	int x , y ;
	int time ;
	int num ;
	char mp[MAX][MAX] ;
	bool check(){
		if( x<0||x>=n || y<0||y>=m )
			return false ;
		return true ;
	}
	bool isWall(){
		return mp[x][y]=='X' ;
	}
	bool isExp(){
		return mp[x][y]>='1'&&mp[x][y]<='9' ;
	}
	void takeOff(){
		mp[x][y] = '.' ;
		return ;
	}
};
node cur , nex ;

void bfs(){
	queue<node> q ;
	cur.x = sx ;
	cur.y = sy ;
	cur.time = cur.num = 0 ;
	vis[sx][sy][0] = 0 ;
	q.push(cur) ;
	while( !q.empty() ){
		cur = q.front() ;q.pop() ;
		if( cur.x == ex && cur.y == ey ){
			if( ans == -1 || cur.time < ans )
				ans = cur.time ;
			continue ;
		}
		for( int i = 0 ; i < 4 ; ++i ){
			nex = cur ;
			nex.x += dir[i][0] ;
			nex.y += dir[i][1] ;
			nex.time++ ;
			if( nex.check() ){
				if( nex.isWall() ){
					if( nex.num>0 ){
						nex.num-- ;
						nex.takeOff() ;
						nex.time++ ;
						q.push(nex) ;
						vis[nex.x][nex.y][nex.num] = nex.time ;
					}
				}else if( nex.isExp() ){
					nex.num += nex.mp[nex.x][nex.y]-'0' ;
					nex.takeOff() ;
					q.push(nex) ;
					vis[nex.x][nex.y][nex.num] = nex.time ;
				}
				else{
					if( vis[nex.x][nex.y][nex.num] == -1 || vis[nex.x][nex.y][nex.num] > nex.time ){
						q.push(nex) ;
						vis[nex.x][nex.y][nex.num] = nex.time ;
					}
				}
			}
		}
	}
	return ;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	while( scanf( "%d%d" , &n , &m ) , n||m ){
		for( int i = 0 ; i < n ; ++i ){
			char tmp[MAX] ;
			scanf( "%s" , tmp ) ;
			for( int j = 0 ; j < m ; ++j ){
				cur.mp[i][j] = map[i][j] = tmp[j] ;
				if( tmp[j] == 'S' )
					sx = i , sy = j ;
				else if( tmp[j] == 'D' )
					ex = i , ey = j ;
			}
		}
		memset(vis,-1,sizeof(vis)) ;
		ans = -1 ;
		bfs() ;
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}