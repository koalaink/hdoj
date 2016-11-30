/*
sample input:
3
22 10
3
7 0 1

2 10
1
1

25 16
3
A B C
 */
#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<queue>
using namespace std;

const int MAX_LENGTH = 505 ;
const int MAX = 5005 ;
bool digit[20] ;
bool vis[MAX] ;
int n , m , c ;

struct node{
	int num[MAX_LENGTH] ;
	int len ;
};

int getMod(const node& a){
	int ans = 0 ;
	for( int i = 0 ; i < a.len ; ++i )
		ans = ( ans*c+a.num[i] ) % n ;
	return ans ;
}

bool bfs(){
	queue<node> q ;
	node cur , nex ;
	cur.len = 0 ;
	q.push(cur) ;
	while( !q.empty() ){
		cur = q.front() ;
		q.pop() ;
		for( int i = (cur.len==0?1:0) ; i < 16 ; ++i ){
			if( digit[i] ){
				nex = cur ;
				nex.num[cur.len] = i ;
				nex.len++ ;
				int mod = getMod(nex) ;
				if( mod ){
					if( !vis[mod] && nex.len <= 500 ){
						vis[mod] = true ;
						q.push(nex) ;
					}
				}
				else{
					for( int i = 0 ; i < nex.len ; ++i )
						printf( "%X" , nex.num[i] ) ;
					printf( "\n" ) ;
					return true ;
				}
			}
		}
	}
	return false ;
}

int main(){
	// freopen("0input.txt","r",stdin) ;
	int T ;
	while( scanf( "%d", &T ) != EOF ){
		while( T-- ){
			memset(digit,false,sizeof(digit)) ;
			memset(vis,false,sizeof(vis)) ;
			scanf( "%d%d" , &n , &c ) ;
			scanf( "%d" , &m ) ;
			while( m-- ){
				int tmp ;
				scanf( "%x" , &tmp ) ;
				digit[tmp] = true;
			}
			if( n == 0 ){
				if( digit[0] ) printf( "0\n" ) ;
				else printf( "give me the bomb please\n") ;
			}
			else if( !bfs() )
				printf( "give me the bomb please\n" ) ;
		}
	}
	return 0 ;
}