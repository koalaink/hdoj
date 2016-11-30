/*
sample input:
3
2 1 0.5 0.5
2 1 0 1
7 7 0.32 0.16
 */
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	// freopen("0input.txt","r",stdin) ;
	long long x , y ;
	double p , q ;
	int t ;
	while( scanf( "%d" , &t ) != EOF ){
		while( t-- ){
			scanf( "%I64d%I64d%lf%lf" , &x , &y , &p , &q ) ;
			double ans1 = q*p*(x+y) + (1-q)*x ;
			double ans2 = q*y + (1-q)*p*(x+y) ;
			// printf( "%lf %lf\n" , ans1 , ans2) ;
			char cho[10] ;
			if( ans1 > ans2 )
				strcpy(cho,"tiger") ;
			else
				strcpy(cho,"wolf") ;
			printf( "%s %.04lf\n" , cho , ans1>ans2?ans1:ans2 ) ;
		}
	}
}