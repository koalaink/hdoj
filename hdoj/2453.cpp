/*
sample input:
3
5 10
##########
#E       #
#*###### #
#S       #
##########
5
10 2
6 10
##########
#E       #
#*######*#
#*######*#
#S       #
##########
5
3 2
1 5
S  *E
2
2 2
*/

#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<queue>
using namespace std ;

const int INF = 0x7f ;
const int MAX = 25 ;
int dir[4][2] = {0,1,0,-1,1,0,-1,0} ;
char map[MAX][MAX] ;
int v1[MAX][MAX] ;
int v2[MAX][MAX] ;
int v3[MAX][MAX] ;
int n , m ;
int d , b , e ;
int ans , ansn ;

struct node{
	int x , y , step , res ;
	int dd , aa , ss ;
	bool check(){
		if( x<0||x>=n || y<0||y>=m || map[x][y]=='#' )
			return false ;
		return true ;
	}
	bool canAcc( int direction ){
		int xx = x ;
		int yy = y ;
		for( int i = 0 ; i < d-1 ; ++i ){
			xx += dir[direction][0] ;
			yy += dir[direction][1] ;
			if( xx<0||xx>=n || yy<0||yy>=m || map[xx][yy]=='#' || map[xx][yy]=='*' )
				return false ;
		}
		return true ;
	}
	bool canPush(){
		if( v1[x][y]>dd || v1[x][y]==dd&&v2[x][y]>aa || v1[x][y]==dd&&v2[x][y]==aa&&v3[x][y]>ss )
			return true ;
		return false ;
	}
	bool operator<(const node& a) const{
		if( dd != a.dd ) return dd>a.dd ;
		if( aa != a.aa ) return aa>a.aa ;
		return step>a.step;
	}
};
node s ;

void bfs(){
	memset(v1,INF,sizeof(v1)) ;
	memset(v2,INF,sizeof(v2)) ;
	memset(v3,INF,sizeof(v3)) ;
	priority_queue<node> q ;
	node cur , nex ;
	v1[s.x][s.y] = v2[s.x][s.y] = v3[s.x][s.y] = 0 ;
	q.push(s) ;
	while( !q.empty() ){
		cur = q.top() ;
		q.pop() ;
		if( map[cur.x][cur.y] == 'E' ){
			ans = cur.step ;
			return ;
		}
		for( int i = 0 ; i < 4 ; ++i ){
			nex = cur ;
			nex.x += dir[i][0] ;
			nex.y += dir[i][1] ;
			nex.step++ ;
			nex.aa++ ;
			if( nex.check() ){
				if( map[nex.x][nex.y] == '*' ){
					if( nex.res >= e ){
						nex.res -= e ;
						nex.dd++ ;
						nex.ss++ ;
						if( nex.canPush() ){
							v1[nex.x][nex.y] = nex.dd ;
							v2[nex.x][nex.y] = nex.aa ;
							v3[nex.x][nex.y] = nex.ss ;
							q.push(nex) ;
						}
					}
				}
				else{
					if( nex.canPush() ){
						v1[nex.x][nex.y] = nex.dd ;
						v2[nex.x][nex.y] = nex.aa ;
						v3[nex.x][nex.y] = nex.ss ;
						q.push(nex) ;
					}
					if( nex.res >= e && nex.canAcc(i) ){
						nex.x += (d-1)*dir[i][0] ;
						nex.y += (d-1)*dir[i][1] ;
						nex.res -= e ;
						nex.ss++ ;
						nex.aa+=d-1 ;
						if( nex.canPush() ){
							v1[nex.x][nex.y] = nex.dd ;
							v2[nex.x][nex.y] = nex.aa ;
							v3[nex.x][nex.y] = nex.ss ;
							q.push(nex) ;
						}
					}
				}
			}
		}
	}
	return ;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	int T ;
	while( scanf( "%d" , &T ) != EOF ){
		while( T-- ){
			scanf( "%d%d" , &n , &m ) ;
			getchar() ;
			for( int i = 0 ; i < n ; ++i ){
				char tmp[MAX] ;
				gets(tmp) ;
				for( int j = 0 ; j < m ; ++j ){
					map[i][j] = tmp[j] ;
					if( tmp[j] == 'S' )
						s.x = i , s.y = j ;
				}
			}
			scanf( "%d" , &d ) ;
			scanf( "%d%d" , &b , &e ) ;
			s.res = b ;
			s.step = s.dd = s.aa = s.ss = 0 ;
			ans = ansn = INF ;
			bfs() ;
			ans!=INF?printf("%d\n",ans):printf("can not reach!\n");
		}
	}
	return 0 ;
}