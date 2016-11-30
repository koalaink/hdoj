#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int t , n , i;
    int a[10001];
    int max , sum , num , index , fir , end ;
    while( scanf( "%d" , &n ) , n ){
        max = -9999 , sum = index = num = fir = end = 0 ;
        for( i = 0 ; i < n ; ++i ){
            scanf( "%d" , a + i );
            if( a[i] < 0 ) num++ ;
        }
        if( num == n )
            printf( "0 %d %d\n" , a[0] , a[n-1] );
        else{
            for( i = 0 ; i < n ; ++i ){
                sum += a[i] ;
                if( sum > max ) max = sum , fir = index , end = i ;
                if( sum < 0 ) index = i + 1 , sum = 0 ;
            }
            printf( "%d %d %d\n" , max , a[fir] , a[end]  );
        }
    }
}