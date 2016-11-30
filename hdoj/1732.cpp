#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<string>
#include<queue>
using namespace std;

const int MAX = 8 ;
char map[MAX][MAX] ;
bool vis[MAX][MAX][MAX][MAX][MAX][MAX][MAX][MAX] ;
int dir[4][2] = {1,0,-1,0,0,1,0,-1} ;
int n , m ;

struct dot{
	int x , y ;
	bool check(){
		if( x<0||x>=n||y<0||y>=m||map[x][y]=='#')
			return false ;
		return true ;
	}
	bool isHole(){
		if( map[x][y] == '@' )
			return true ;
		return false;
	}
	void show(){
		printf("%d %d " , x , y );
	}
};

struct node{
	dot p , b[3] ;
	int step ;
	void setV(){
		vis[p.x][p.y][b[0].x][b[0].y][b[1].x][b[1].y][b[2].x][b[2].y] = true ;
		return ;
	}
	bool isV(){
		return vis[p.x][p.y][b[0].x][b[0].y][b[1].x][b[1].y][b[2].x][b[2].y];
	}
	bool isEnd(){
		if( b[0].isHole() && b[1].isHole() && b[2].isHole() )
			return true ;
		return false ;
	}
	int inBox(){
		for( int i = 0 ; i < 3 ; ++i )
			if( p.x==b[i].x && p.y==b[i].y )
				return i ;
		return -1 ;
	}
	bool isBIB(int index ){
		for( int i = 0 ; i < 3 ; ++i ){
			if( i == index ) continue ;
			if( b[i].x == b[index].x && b[i].y == b[index].y )
				return true ;
		}
		return false ;
	}
};

node cur , nex ;

void bfs(){
	queue<node> q ;
	cur.setV() ;
	q.push(cur) ;
	while( !q.empty() ){
		cur = q.front() ;
		q.pop() ;
		if( cur.isEnd() ){
			printf("%d\n" , cur.step) ;
			return ;
		}
		for( int i = 0 ; i < 4 ; ++i ){
			nex = cur ;
			nex.p.x += dir[i][0] ;
			nex.p.y += dir[i][1] ;
			nex.step++ ;
			if( nex.p.check() ){
				int boxNO = nex.inBox() ;
				if( boxNO != -1 ){
					nex.b[boxNO].x +=  dir[i][0] ;
					nex.b[boxNO].y +=  dir[i][1] ;
					if( nex.b[boxNO].check() && !nex.isBIB(boxNO) ){
						if( !nex.isV() ){
							nex.setV() ;
							q.push(nex) ;
						}
					}
				}
				else{
					if( !nex.isV() ){
						nex.setV() ;
						q.push(nex) ;
					}
				}
			}
		}
	}
	printf("-1\n" );
	return ;
}

int main(){
	while( scanf( "%d%d" , &n , &m ) != EOF ){
		int index = 0 ;
		for( int i = 0 ; i < n ; ++i ){
			char tmp[MAX+1] ;
			scanf( "%s" , tmp ) ;
			for( int j = 0 ; j < m ; ++j ){
				map[i][j] = tmp[j] ;
				if( tmp[j] == 'X' )
					cur.p.x = i , cur.p.y = j ;
				else if( tmp[j] == '*' )
					cur.b[index].x = i , cur.b[index++].y = j ;
			}
		}
		memset(vis,false,sizeof(vis)) ;
		cur.step = 0 ;
		bfs() ;
	}
	return 0 ;
}