#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

string w[50005];

int main(){
    int t , n , i , j , ans ;
    scanf( "%d" , &t );
    while( t-- ){
        ans = 0 ;
        scanf( "%d" , &n );
        for( i = 0 ; i < n ; ++i )
            cin>>w[i];
        sort( w , w + n );
        for( i = 0 ; i < n ; ++i )
            for( j = i + 1 ; j < n ; ++j )
                if( w[i] == w[j].substr( 0 , w[i].length() ) )
                    ++ans;
                else break;
        if( ans > 11519 ) ans = ans % 11519 ;
        printf( "%d\n" , ans );
    }
}