/*
sample input:
3 2
1 2
1 3
4 3
1 2
3 2
4 2
0 0
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 10001 ;
vector<int> edge[MAX] ;
int con[MAX] ;
bool vis[MAX] ;
int n , m ;

int bfs(){
	memset(vis,false,sizeof(vis)) ;
	memset(con,0,sizeof(con)) ;
	vis[1] = true ;
	queue<int> q ;
	q.push(1) ;
	int ans = 0 ;
	while( !q.empty() ){
		int cur = q.front() ;
		q.pop() ;
		for( int i = 0 ; i < edge[cur].size() ; ++i )
			con[edge[cur][i]] = cur ;
		for( int i = 1 ; i <= n ; ++i )
			if( !vis[i] && con[i] != cur )
				vis[i] = true , q.push(i) , ans++ ;
	}
	return ans ;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	int f , t , cas = 1 ;
	while( scanf( "%d%d" , &n , &m ) , n||m ){
		for( int i = 1 ; i <= n ; ++i )
			edge[i].clear() ;

		while( m-- ){
			scanf( "%d%d" , &f , &t ) ;
			edge[f].push_back(t) ;
			edge[t].push_back(f) ;
		}

		printf( "Case %d: %d\n" , cas++ , bfs() ) ;
	}
	return 0 ;
}