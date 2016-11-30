#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define N 10005
#define M 20005

struct node{
	int a , b ;
	char ch ;
};

vector<int>v[N] ;
int flag , mark ;
int indegree[N] ;
int father[N] ;
node edge[M] ;
int n , m ;
int cnt ;

void Init(){
	cnt = n ;
	flag = mark = 0 ;
	for( int i = 0 ; i < n ; ++i ){
		indegree[i] = 0 ;
		father[i] = i ;
		v[i].clear() ;
	}
	return ;
}

int find( int x ){
	if( x != father[x] )
		father[x] = find(father[x]) ;
	return father[x] ;
}

void Union( int x , int y ){
	x = find(x) ;
	y = find(y) ;
	if( x != y ){
		if( x > y )
			father[y] = x ;
		else
			father[x] = y ;
	}
	--cnt ;
	return ;
}

void Topo(){
	queue<int> q ;
	for( int i = 0 ; i < n ; ++i ){
		if( indegree[i] == 0 && find(i) == i )
			q.push(i) ;
	}
	while( !q.empty() ){
		if( q.size() > 1 ) mark = 1 ;
		int x = q.front() ;
		q.pop() ;
		--cnt ;
		for( int i = 0 ; i < v[x].size() ; ++i ){
			if( --indegree[v[x][i]] == 0 )
				q.push( v[x][i] ) ;
		}
	}
	if( flag || cnt > 1 )
		printf( "CONFLICT\n" ) ;
	else if( mark )
		printf( "UNCERTAIN\n" ) ;
	else
		printf( "OK\n" ) ;
	return ;
}

int main(){
	// freopen( "0input.txt" , "r" , stdin ) ;
	while( scanf( "%d%d" , &n , &m ) != EOF ){
		Init() ;
		for( int i = 0 ; i < m ; ++i ){
			scanf( "%d %c %d" , &edge[i].a , &edge[i].ch , &edge[i].b ) ;
			if( edge[i].ch == '=' ){
				Union(edge[i].a,edge[i].b) ;
			}
		}
		for( int i = 0 ; i < m ; ++i ){
			if( edge[i].ch == '=' ) continue ;
			int x = find(edge[i].a) ;
			int y = find(edge[i].b) ;
			if( x == y ) flag = true ;
			if( edge[i].ch == '>' ){
				v[x].push_back(y) ;
				indegree[y]++ ;
			}
			else{
				v[y].push_back(x) ;
				indegree[x]++ ;
			}
		}
		Topo() ;
	}
	return 0 ;
}