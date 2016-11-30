#include<iostream>
#include<stdio.h>
using namespace std;

const int INF = 1000000 ;
const int MAX = 205;
int matrix[MAX][MAX];
bool visit[MAX];
int dist[MAX];
int n , m , sp , ep ;
bool flag;

void dijkstra(){
    for( int i = 0 ; i < n ; ++i )
        dist[i] = matrix[sp][i] ;
    visit[sp] = true;
    dist[sp] = 0 ;
    for( int i = 1 ; i < n ; ++i ){
        int min = INF ;
        int index = sp ;
        for( int j = 0 ; j < n ; ++j ){
            if( !visit[j] && dist[j] < min ){
                min = dist[j] ;
                index = j ;
            }
        }
        visit[index] = true;
        if( min == INF ){
            flag = true ;
            return ;
        }
        if( index == ep ){
            flag = false ;
            printf( "%d\n" , min );
            return ;
        }
        for( int j = 0 ; j < n ; ++j ){
            if( !visit[j] && matrix[index][j]<INF && matrix[index][j] + min < dist[j] )
                dist[j] = min + matrix[index][j] ;
        }
    }
    return ;
}

int main(){
    int f , t , w ;
    while( scanf( "%d%d" , &n , &m ) != EOF ){
        memset( matrix , INF , sizeof(matrix) );
        memset( visit , false , sizeof(visit) );
        memset( dist , 0 , sizeof(dist) );
        for( int i = 0 ; i < m ; ++i ){
            scanf( "%d%d%d" , &f , &t , &w );
            if( matrix[f][t] > w )
                matrix[f][t] = matrix[t][f] = w ;
        }
        scanf( "%d%d" , &sp , &ep );
        if( sp == ep ){
            printf( "0\n" );
            continue;
        }
        dijkstra();
        if( flag )
            printf( "-1\n" );
    }
    return 0;
}