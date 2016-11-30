#include<iostream>
#include<stdio.h>
using namespace std;

const int MAX = 1005 ;
double matrix[MAX][MAX];
bool visit[MAX];
double dist[MAX];
int n ;

void Dijkstra( int s , int e ){
    int i , j ;
    for( i = 1 ; i <= n ; ++i )
        dist[i] = matrix[s][i] ;
    dist[s] = 0 ;
    visit[s] = true ;
    for( i = 1 ; i < n ; ++i ){
        double max = 0.0 ;
        int index = s ;
        for( j = 1 ; j <= n ; ++j ){
            if( !visit[j] && dist[j] > max ){
                max = dist[j] ;
                index = j;
            }
        }
        if( max == 0.0 ){
            printf( "What a pity!\n" );
            return ;
        }
        if( index == e ){
            printf( "%.3lf\n" , max );
            return ;
        }
        visit[index] = true ;
        for( j = 1 ; j <= n ; ++j )
            if( !visit[j] && matrix[index][j] != 0.0 && matrix[index][j] * max > dist[j] )
                dist[j] = matrix[index][j] * max ;
    }
    return ;
}

int main(){
    int t , sp , ep ;
    while( scanf( "%d" , &n ) != EOF ){
        memset( matrix , 0 , sizeof(matrix) );
        for( int i = 1 ; i <= n ; ++i )
            for( int j = 1 ; j <= n ; ++j )
                scanf( "%lf" , &matrix[i][j] );
        scanf( "%d" , &t );
        while( t-- ){
            scanf( "%d%d" , &sp , &ep );
            memset( visit , false , sizeof(visit) );
            memset( dist , 0 , sizeof(dist) );
            if( sp == ep ){
                printf( "1.000\n" );
                continue;
            }
            Dijkstra( sp , ep );
        }
    }
    return 0;
}