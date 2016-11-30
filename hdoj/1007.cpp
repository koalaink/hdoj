#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

struct point{
	double x , y ;
};

point p[100001] ;

int cmp1( point a , point b ){
	if( a.x == b.x )
		return a.y < b.y ;
	return a.x < b.x ;
}

int cmp2( point a , point b ){
	if( a.y == b.y )
		return a.x < b.x ;
	return a.y < b.y ;
}

int main(){
	// freopen( "0input.txt" , "r" , stdin ) ;
	int n ;
	double ans ;
	while( scanf( "%d" , &n ) , n ){
		ans = 0xffffff ;
		for( int i = 0 ; i < n ; ++i )
			scanf( "%lf%lf" , &p[i].x , &p[i].y ) ;
		sort( p , p+n , cmp1 ) ;
		for( int i = 1 ; i < n ; ++i ){
			double tmp = (p[i].x-p[i-1].x)*(p[i].x-p[i-1].x) + (p[i].y-p[i-1].y)*(p[i].y-p[i-1].y) ;
			if( tmp < ans ) ans = tmp ;
		}
		sort( p , p+n , cmp2 ) ;
		for( int i = 1 ; i < n ; ++i ){
			double tmp = (p[i].x-p[i-1].x)*(p[i].x-p[i-1].x) + (p[i].y-p[i-1].y)*(p[i].y-p[i-1].y) ;
			if( tmp < ans ) ans = tmp ;
		}
		printf( "%.02lf\n" , sqrt(ans)/2 ) ;
	}
	return 0 ;
}