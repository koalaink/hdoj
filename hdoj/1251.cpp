/*
sample input:
banana
band
bee
absolute
acm

ba
b
band
abc
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 26
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
        int id = str[i] - 'a' ;
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
    return ;
}

int findTrie( char *str ){
    int len = strlen(str) ;
    Trie *p = root , *q ;
    for( int i = 0 ; i < len ; ++i ){
        int id = str[i] - 'a' ;
        p = p->next[id] ;
        if( p == NULL )
            return 0 ;
    }
    return p->v ;
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
    root = (Trie *)malloc(sizeof(Trie)) ;
    str = (char *)malloc(sizeof(char)*MAXL) ;
    for( int i = 0 ; i < MAX ; ++i )
        root->next[i] = NULL ;
    while( gets(str) && str[0] != '\0' )
        createTrie(str) ;

    while( scanf( "%s" , str ) != EOF ){
        int ans = findTrie(str) ;
        printf( "%d\n" , ans ) ;
    }
    return 0;
}