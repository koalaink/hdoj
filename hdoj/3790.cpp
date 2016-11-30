#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

const int INF = 10000;
const int MAX = 1005;
int matrix[MAX][MAX];
int p[MAX][MAX];
bool visit[MAX];
int dist[MAX];
int pri[MAX];
int n ;

void Dijkstra( int s ){
    int i , j ;
    for( i = 1 ; i <= n ; ++i ){
        dist[i] = matrix[s][i];
        visit[i] = false;
        pri[i] = p[s][i] ;
    }
    dist[i] = 0 ;
    visit[i] = true;
    for( i = 1 ; i < n ; ++i ){
        int min = INF;
        int index = s;
        for( j = 1 ; j <= n ; ++j ){
            if( visit[j] ) continue;
            if( min > dist[j] ){
                min = dist[j];
                index = j ;
            }/*else if( min == dist[j] ){
                if( pri[index] > pri[j] )
                    index = j;
            }*/
        }
        if( min == INF )
            break;
        visit[index] = true;
        for( j = 1 ; j <= n ; ++j ){
            if( visit[j] ) continue;
            if( min + matrix[index][j] < dist[j] ){
                dist[j] = min + matrix[index][j] ;
                pri[j] = pri[index] + p[index][j] ;
            }else if( min + matrix[index][j] == dist[j] ){
                if( pri[j] > pri[index] + p[index][j] )
                    pri[j] = pri[index] + p[index][j] ;
            }
        }
    }
    return ;
}

int main(){
    int m , a , b , d , pr ;
    // freopen( "0input.txt" , "r" , stdin );
    while( scanf( "%d%d" , &n , &m ) , m || n ){
        memset( matrix , INF , sizeof(matrix) );
        memset( p , INF , sizeof(p) );
        while( m-- ){
            scanf( "%d%d%d%d" , &a , &b , &d , &pr );
            if( matrix[a][b] > d ){
                matrix[a][b] = matrix[b][a] = d;
                p[a][b] = p[b][a] = pr;
            }else if( matrix[a][b] == d && p[a][b] > pr )
                p[a][b] = pr;
        }
        scanf( "%d%d" , &a , &b );
        Dijkstra(a);
        printf( "%d %d\n" , dist[b] , pri[b] );
    }
    return 0;
}