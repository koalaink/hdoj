#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

const int INF = 10005;
const int MAX = 1005;
char map[MAX][MAX];
int visit[MAX][MAX];
int dir[4][2] = { 1 , 0 , -1 , 0 , 0 , 1 , 0 , -1 };
int m , n , sx , sy , ex , ey , ans ;

struct node{
	int x , y , d;
	bool check(){
		if( x < 0 || x > m || y < 0 || y > n )
			return false;
		return true;
	}
	friend bool operator<(const node& a,const node& b){
		return (a.d>b.d);
	}
};

void bfs(){
	node now , next ;
	memset( visit , INF , sizeof(visit) );
	now.x = sx ;
	now.y = sy ;
	now.d = 0 ;
	priority_queue<node> q;
	q.push(now);
	while( !q.empty() ){
		now = q.top();
		q.pop();
		if( now.x == ex && now.y == ey ){
			ans = now.d ;
			return ;
		}
		for( int i = 0 ; i < 4 ; ++i ){
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if( !next.check() ) continue;
			if( map[next.x][next.y] == 'X' )
				next.d = now.d ;
			else
				next.d = now.d + 1;
			if( next.d < visit[next.x][next.y] ){
				visit[next.x][next.y] = next.d;
				q.push(next);
			}
		}
	}
	return ;
}

int main(){
	bool blank=false;
	while( scanf( "%d%d" , &m , &n ) , n || m ){
		for( int i = 1 ; i <= m ; ++i ){
			char tmp[MAX];
			scanf( "%s" , tmp );
			for( int j = 1 ; j <= n ; ++j )
				map[i][j] = tmp[j-1];
		}
		scanf( "%d%d" , &sx , &sy );
		scanf( "%d%d" , &ex , &ey );
		ans = INF ;
		bfs();
		printf( "%d\n" , ans );
	}
	return 0;
}