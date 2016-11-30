/*
sample input:
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 10
#define MAXL 15
using namespace std;

struct Trie{
	Trie *next[MAX];
	int v ;
};
Trie *root;

void createTrie( char *str ){
	int len = strlen(str);
	Trie *p = root , *q ;
	for( int i = 0 ; i < len ; ++i ){
		int id = str[i] - '0' ;
		if( p->next[id] == NULL ){
			q = (Trie *)malloc(sizeof(Trie)) ;
			q->v = 1 ;
			for( int j = 0 ; j < MAX ; ++j ){
				q->next[j] = NULL;
			}
			p->next[id] = q ;
			p = p->next[id] ;
		}
		else{
			p->next[id]->v++;
			p = p->next[id] ;
		}
	}
	p->v = -1 ;
	return ;
}

int findTrie( char *str ){
	int len = strlen(str) ;
	Trie *p = root , *q ;
	for( int i = 0 ; i < len ; ++i ){
		int id = str[i] - '0' ;
		p = p->next[id] ;
		if( p == NULL )
			return false ;
		if( p->v == -1 )
			return true ;
	}
	return true ;
}

void freeTrie( Trie *p ){
	if( p == NULL )
		return ;
	for( int i = 0 ; i < MAX ; ++i )
		if( p->next[i] != NULL ) freeTrie(p->next[i]);
	free(p) ;
	return ;
}

int main(){
	// freopen("0input.txt","r",stdin);
	char *str ;
	str = (char *)malloc(sizeof(char)*MAXL) ;
	int t , n ;
	while( scanf( "%d" , &t ) != EOF ){
		while( t-- ){
			bool flag = false ;
			root = (Trie *)malloc(sizeof(Trie)) ;
			for( int i = 0 ; i < MAX ; ++i )
				root->next[i] = NULL ;
			scanf( "%d" , &n ) ;
			for( int i = 0 ; i < n ; ++i ){
				scanf( "%s" , str ) ;
				if( findTrie(str) )
					flag = true ;
				if( flag ) continue ;
				createTrie(str) ;
			}
			if( flag ) printf( "NO\n" ) ;
			else printf( "YES\n" ) ;
			freeTrie(root) ;
		}
	}
	return 0;
}