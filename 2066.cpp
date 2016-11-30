#include<iostream>
#include<stdio.h>
using namespace std;

const int INF = 10000 ;
const int MAX = 1005 ;
int matrix[MAX][MAX];
int dist[MAX];
bool visit[MAX];
bool ep[MAX];
int n ;

void Dijkstra(){
    int i , j ;
    for( i = 0 ; i < n ; ++i )
        dist[i] = matrix[0][i] ;
    visit[0] = true;
    dist[0] = 0;
    for( i = 1 ; i < n ; ++i ){
        int min = INF ;
        int index = 0 ;
        for( j = 0 ; j < n ; ++j ){
            if( !visit[j] && dist[j] < min ){
                min = dist[j] ;
                index = j;
            }
        }
        if( ep[index] ){
            printf( "%d\n" , min );
            return ;
        }
        visit[index] = true;
        for( j = 0 ; j < n ; ++j )
            if( !visit[j] && matrix[index][j] + min < dist[j] )
                dist[j] = matrix[index][j] + min ;
    }
    return ;
}

int main(){
    int t , s , d , i , j , ans ;
    int a , b , time ;
    int st , en ;
    while( scanf( "%d%d%d" , &t , &s , &d ) != EOF ){
        memset( matrix , INF , sizeof(matrix) );
        memset( dist , 0 , sizeof(dist) );
        memset( visit , false , sizeof(visit) );
        memset( ep , false , sizeof(ep) );
        n = 0 ;
        for( i = 0 ; i < t ; ++i ){
            scanf( "%d%d%d" , &a , &b , &time );
            if(time<matrix[a][b])
                matrix[a][b] = matrix[b][a] = time ;
            a = a>b?a:b;
            n = n>a?n:a;
        }
        n++;
        for( i = 0 ; i < s ; ++i ){
            scanf( "%d" , &st );
            matrix[0][st] = matrix[st][0] = 0 ;
        }
        for( i = 0 ; i < d ; ++i ){
            scanf( "%d" , &en );
            ep[en] = true;
        }
        Dijkstra();
    }
    return 0;
}