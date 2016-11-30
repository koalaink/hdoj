#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int nsum[2] , pmax[2] , cmax[2] , rmax[2] , sum ;
    int m , n , i , j , tmp ;
    while( scanf( "%d%d" , &m , &n ) != EOF ){
        memset(pmax,0,sizeof(pmax));
        memset(rmax,0,sizeof(rmax));
        for( i = 0 ; i < m ; ++i ){
            memset(cmax,0,sizeof(cmax));
            memset(nsum,0,sizeof(nsum));
            for( j = 0 ; j < n ; ++j ){
                scanf( "%d" , &tmp );
                nsum[0] = cmax[1]>cmax[0]?cmax[1]:cmax[0];
                nsum[1] = cmax[0]+tmp ;
                cmax[0] = nsum[0];
                cmax[1] = nsum[1];
            }
            sum = cmax[0]>cmax[1]?cmax[0]:cmax[1] ;
            rmax[0] = pmax[1]>pmax[0]?pmax[1]:pmax[0];
            rmax[1] = pmax[0]+sum;
            pmax[0] = rmax[0];
            pmax[1] = rmax[1];
        }
        printf( "%d\n" , pmax[0]>pmax[1]?pmax[0]:pmax[1] );
    }
    return 0;
}