#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int l , n , i , j , c , t , vr , vt1 , vt2 ;
    int dis[105];
    double dp[105] , tmp , tmin ;
    while( scanf( "%d" , &l ) != EOF ){
        scanf( "%d%d%d" , &n , &c , &t );
        scanf( "%d%d%d" , &vr , &vt1 , &vt2 );
        for( i = 1 ; i <= n ; ++i )
            scanf( "%d" , dis + i );
        memset( dp , 0 , sizeof(dp) );
        dis[0] = 0 ;
        dis[i] = l ;
        for( i = 1 ; i < n + 2 ; ++i ){
            tmin = 0xffffff ;
            for( j = 0 ; j < i ; ++j ){
                if( dis[i] - dis[j] > c )
                    tmp = (double)c/vt1 + (double)(dis[i] - dis[j] - c)/vt2;
                else
                    tmp = (double)(dis[i] - dis[j])/vt1 ;
                tmp += dp[j] ;
                if(j) tmp += t;
                if( tmp < tmin ) tmin = tmp ;
            }
            dp[i] = tmin ;
        }
        if( (double)l/vr > dp[n+1] )
            printf( "What a pity rabbit!\n" );
        else
            printf( "Good job,rabbit!\n");
    }
    return 0;
}