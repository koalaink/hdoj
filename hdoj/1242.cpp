#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int n , m ;
char map[205][205];
bool vis[205][205];
int dir[4][2] = { 1 , 0 , -1 , 0 , 0 , 1 , 0 , -1 };
int sx , sy , ex , ey , ans ;

struct node{
    int x , y ;
    int time;
    bool check(){
        if( x<0 || x>=n || y<0 || y>=m || map[x][y] == '#' )
            return false;
        return true;
    }
};

void bfs(){
    node now , next;
    now.x = sx ;
    now.y = sy ;
    now.time = 0 ;
    vis[sx][sy] = true;
    queue<node> q;
    q.push(now);
    while( !q.empty() ){
        now = q.front();
        q.pop();
        if( map[now.x][now.y] == 'r' ){
            ans = now.time;
            return ;
        }
        for( int i = 0 ; i < 4 ; ++i ){
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            next.time = now.time;
            if( !next.check() ) continue;
            if( vis[next.x][next.y] ) continue;
            if( map[next.x][next.y] == 'x' )
                next.time += 2;
            else
                next.time += 1;
            vis[next.x][next.y] = true;
            q.push(next);
        }
    }
    return ;
}

int main(){
    while( scanf( "%d%d" , &n , &m ) != EOF ){
        for( int i = 0 ; i < n ; ++i ){
            char tmp[205];
            scanf( "%s" , tmp );
            for( int j = 0 ; j < m ; ++j ){
                map[i][j] = tmp[j] ;
                if( tmp[j] == 'a' )
                    sx = i , sy = j;
            }
        }
        memset( vis , false , sizeof(vis) );
        ans = -1;
        bfs();
        if( ans != -1 )
            printf( "%d\n" , ans );
        else
            printf( "Poor ANGEL has to stay in the prison all his life.\n" );
    }
    return 0;
}