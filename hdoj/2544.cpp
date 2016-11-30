#include<iostream>
#include<stdio.h>
using namespace std;

const int INF = 0xffffff;
const int MAX = 105;
int matrix[MAX][MAX];
int visit[MAX];
int dist[MAX];
int n , e ;

void dijkstra(){
    int v = 1 ;
    for( int i = 1 ; i <= n ; ++i )
        if( i != v && matrix[v][i] )
            dist[i] = matrix[v][i];
        else
            dist[i] = INF ;
    visit[v] = true;
    dist[v] = 0 ;
    for( int i = 1 ; i < n ; ++i ){
        int min = INF ;
        int index ;
        for( int j = 1 ; j <= n ; ++j ){
            if( !visit[j] && dist[j] < min ){
                min = dist[j] ;
                index = j;
            }
        }
        if( index == n ){
            printf( "%d\n" , min );
            return ;
        }
        visit[index] = true;
        for( int j = 1 ; j <= n ; ++j ){
            if( !visit[j] && matrix[index][j] && min + matrix[index][j] < dist[j] )
                dist[j] = min + matrix[index][j] ;
        }
    }
    return ;
}

int main(){
    int f , t , w ;
    while( scanf( "%d%d" , &n , &e ) , n || e ){
        memset( matrix , 0 , sizeof(matrix) );
        memset( visit , false , sizeof(visit) );
        memset( dist , 0 , sizeof(dist) );
        for( int i = 0 ; i < e ; ++i ){
            scanf( "%d%d%d" , &f , &t , &w );
            matrix[f][t] = matrix[t][f] = w ;
        }
        dijkstra();
    }
    return 0;
}