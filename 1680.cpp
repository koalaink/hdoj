/*
2
........
.......D
........
.....F..
..DDD...
..DFDD..
..DDD...
........
7 6
3 7
........
........
........
........
........
........
........
........
3 1
6 3
 */

#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

const int MAX = 15 ;
char map[MAX][MAX] ;
int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};

struct node{
	int x , y ;
	int tx , ty ;
	bool checkK(){
		if( x<0||x>=8||y<0||y>=8||map[y][x]!='.'||x==tx+1&&y==ty+1||x==tx-1&&y==ty+1)
			return false ;
		return true ;
	}
	bool checkP(){
		if( map[ty][tx]=='F' || x==tx && y == ty )
			return false ;
		return true ;
	}
};

node s ;

void bfs(){
	node cur , next ;
	queue<node> q ;
	q.push(s) ;
	bool isFirst = true ;
	while( !q.empty() ){
		cur = q.front() ;
		q.pop() ;
		if( !isFirst ){
			if( cur.ty == 7 ){
				printf( "Black\n" ) ;
				return ;
			}
			cur.ty++ ;
			if( !cur.checkP() ){
				printf( "White\n" ) ;
				return ;
			}
		}
		isFirst = false ;
		bool canMove = false ;
		for( int i = 0 ; i < 8 ; ++i ){
			next = cur ;
			next.x += dir[i][0] ;
			next.y += dir[i][1] ;
			if( next.checkK() ){
				canMove = true ;
				if( next.x == next.tx && next.y == next.ty ){
					printf( "White\n" ) ;
					return ;
				}
				q.push(next) ;
			}
		}
		if( !canMove ){
			printf( "Black\n" ) ;
			return ;
		}
	}
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	int t , xk , yk , xp , yp ;
	while( scanf( "%d" , &t ) != EOF ){
		while( t-- ){
			for( int i = 0 ; i < 8 ; ++i ){
				char tmp[MAX] ;
				scanf( "%s" , tmp ) ;
				for( int j = 0 ; j < 8 ; ++j ){
					map[i][j] = tmp[j] ;
				}
			}
			scanf( "%d%d" , &xk , &yk ) ;
			scanf( "%d%d" , &xp , &yp ) ;
			s.x = xk - 1 ;
			s.y = 8 - yk ;
			s.tx = xp - 1 ;
			s.ty = 8 - yp ;
			bfs();
		}
	}
	return 0 ;
}